/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:51:34 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/19 16:03:36 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_line(int const fd, char **line, t_elem *curr, int nbcharline)
{
	while (1)
	{
		if ((curr->filenbcharread == 0)
			|| (curr->fileposition == curr->filenbcharread))
		{
			if ((curr->filenbcharread = read(fd, curr->buff, BUFF_SIZE)) == 0)
				return (*line[0] == 0 ? 0 : 1);
			curr->fileposition = 0;
			realloc_str(line, nbcharline, curr->filenbcharread);
		}
		while (curr->fileposition < curr->filenbcharread)
		{
			if (curr->buff[curr->fileposition] == '\n')
			{
				curr->fileposition++;
				return (1);
			}
			line[0][nbcharline++] = curr->buff[curr->fileposition++];
			if (curr->fileposition == curr->filenbcharread)
			{
				curr->filenbcharread = 0;
				curr->fileposition = 0;
			}
		}
	}
}

int			get_next_line(int const fd, char **line)
{
	t_elem			*curr;
	static t_l		*mylist = NULL;
	char			c[1];

	mylist = mylist ? mylist : initialisation();
	if ((fd < 0) || (mylist == NULL) || (read(fd, c, 0) == -1) || !line)
		return (-1);
	curr = mylist->first;
	while ((curr != NULL) && (curr->fd != fd))
		curr = curr->next;
	if (curr == NULL)
	{
		curr = malloc(sizeof(t_elem));
		curr->fileposition = 0;
		curr->fd = fd;
		curr->next = mylist->first;
		mylist->first = curr;
		curr->filenbcharread = 0;
	}
	*line = malloc(1);
	line[0][0] = '\0';
	return (get_line(fd, line, curr, 0));
}
