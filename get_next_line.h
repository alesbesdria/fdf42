/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:42:57 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/19 16:23:13 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 1

typedef struct		s_elem
{
	char			buff[BUFF_SIZE];
	long long		fileposition;
	long long		filenbcharread;
	int				fd;
	struct s_elem	*next;
}					t_elem;

int					get_next_line(int const fd, char **line);

#endif
