/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intboardset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:13:54 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:13:59 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			**ft_intboardset(int x, int y, int c)
{
	int		**rslt;
	int		i;
	int		j;

	j = 0;
	rslt = (int**)malloc((sizeof(int*) * y) + sizeof(int) * (x * y));
	if (!rslt)
		return (NULL);
	while (j < y)
	{
		i = 0;
		rslt[j] = (int*)rslt + 2 * y + (x * j);
		while (i < x)
		{
			rslt[j][i] = c;
			i++;
		}
		j++;
	}
	return (rslt);
}
