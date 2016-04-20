/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloclili.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:33:18 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/19 15:53:30 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_l		*initialisation(void)
{
	t_l		*list;

	list = malloc(sizeof(list));
	if (list == NULL)
	{
		return (NULL);
	}
	list->first = NULL;
	return (list);
}

void	realloc_str(char **source, long len, long lenmore)
{
	void	*temp;

	temp = *source;
	*source = malloc(len + lenmore + 1);
	ft_memset(*source, '\0', len + lenmore + 1);
	ft_strncpy(*source, temp, len);
	free(temp);
}
