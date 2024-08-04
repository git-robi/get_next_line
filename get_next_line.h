/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:07:06 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/04 20:53:42 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

typedef struct s_list
{
	char		content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void    read_and_putnode(int fd, t_list **list);
int     new_line(t_list **list);
t_list  *add_new_node(t_list **list, int is_new_list);
void    reset_list(t_list **list);
void    free_all(t_list **list);
void    fill_line(t_list *list, char *line, int line_len);
t_list  *get_last_node(t_list **list);
void    remove_last_node(t_list **list);

#endif
