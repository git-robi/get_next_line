#include "get_next_line.h"

void	remove_last_node(t_list **list)
{
	t_list	*tmp;
	t_list	*new_last;

	if(!*list)
		return ;
	tmp = *list;
	if (tmp->next == NULL)
	{
		free(tmp);
		*list = NULL;
		return ;
	}
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	new_last->next = NULL;
}

t_list	*get_last_node(t_list **list)
{
	t_list	*last_node;

	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

void	fill_line(t_list *list, char *line, int	line_len)
{
	int	i;
	int	j;
	t_list	*tmp;

	tmp = list;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] != '\0' && j < line_len && tmp->content[i] != '\n')
		{
			line[j] = tmp->content[i];
			j++;
			i++;
		}
		if (tmp->content[i] == '\n') {
			line[j] = '\n';
			j++;
			break;
		}
		tmp = tmp->next;
	}
	line[j] = '\0';
}

void	free_all(t_list **list)
{
	t_list	*current;
	t_list	*tmp;

	if(!list)
		return ;
	current = *list;
	while (current->next)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free (current);
	*list = NULL;
}
