#include "get_next_line.h"

//int counter = 0;
void	fill_new_list(t_list *tmp, t_list *new_list)
{
	t_list		*new_node;
	int		j;
	int		i;

	new_node = new_list;
	new_node->content[0] = '\0';
	i = 0;
	while (tmp->content[i] != '\n')
		i++;
	i++;
	while (tmp)
	{
		j = 0;
		while (tmp->content[i] != '\0')
		{
				new_node->content[j] = tmp->content[i];
				i++;
				j++;
		}
		new_node->content[j] = '\0';
		tmp = tmp->next;
		if (tmp != NULL && new_node->content[0] != '\0')
		{
			new_node->next = malloc(sizeof(t_list));
			new_node = new_node->next;
			if (new_node == NULL)
				return ;
		}
		i = 0;
	}
}

void	reset_list(t_list **list)
{
	int	i;
	t_list	*tmp;
	t_list	*new_list;

	new_list = add_new_node(list, 1);
	if (new_list == NULL)
		return ;
	tmp = *list;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] != '\0')
		{
			if (tmp->content[i] == '\n')
				break;
			i++;
		}
		if (tmp->content[i] == '\n')
		{
			fill_new_list(tmp, new_list);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *list;
	*list = new_list;
	free_all(&tmp);
}

t_list	*add_new_node(t_list **list, int is_new_list)
{
	t_list	*new_node;
	t_list	*tmp;
	int	i;
	
	i = 0;
	tmp = *list;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	while (i <= BUFFER_SIZE)
	{
		new_node->content[i] = '\0';
		i++;
	}
	if (is_new_list)
		return (new_node);
	if (!*list)
	{
		*list = new_node;
		return (new_node);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (new_node);
}

int	new_line(t_list **list)
{
	int	i;
	t_list	*node;

	if (!*list)
		return (0);
	node = *list;
	i = 0;
	while (node != NULL)
	{
		while (node->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node->content[i] == '\n')
				return (1);
			i++;
		}
		i = 0;
		node = node->next;
	}
	return (0);
}	

void	read_and_putnode(int fd, t_list **list)
{
	t_list	*new_node;
	int	bytes;

	bytes = BUFFER_SIZE;
	while (bytes == BUFFER_SIZE && !(new_line(list)))
	{
		new_node = add_new_node(list, 0);
		if (!new_node)
		{
			free_all(list);
			return ;
		}
		new_node->next = NULL;
		bytes = read(fd, new_node->content, BUFFER_SIZE);
	}
	if (bytes == -1)
	{
		free_all(list);
	}
	if (bytes == 0)
	{
		remove_last_node(list);
	}
}

int	count_len(t_list **list)
{
	t_list	*node;
	int	len;
	int	i;

	len = 0;
	node = *list;
	while (node)
	{
		i = 0;
		while (node->content[i] != '\0')
		{
			len++;
			if (node->content[i] == '\n')
				return (len);
			i++;
		}
		node = node->next;
	}
	return (len);
}
	
char	*get_next_line(int fd)
{
	char		*line;
	static t_list	*list;
	int		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || read(fd, 0, 0) == -1)
	{
		free_all(&list);
		return (NULL);
	}
	line_len = 0;
	read_and_putnode(fd, &list);
	if (list == NULL)
		return (NULL);
	line_len = count_len(&list);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
	{
		free_all(&list);
		return (NULL);
	}
	fill_line(list, line, line_len);
	reset_list(&list);
	if (list->content[0] == '\0')
		list = NULL;
	return (line);
}
