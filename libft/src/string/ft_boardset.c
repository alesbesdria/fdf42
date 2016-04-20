/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:29:57 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:30:03 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_boardset(int x, int y, char c)
{
	char	**rslt;
	int		i;
	int		j;

	j = 0;
	rslt = (char**)malloc((sizeof(char*) * y) + (x * y));
	if (!rslt)
		return (NULL);
	while (j < y)
	{
		i = 0;
		rslt[j] = (char*)((char*)rslt) + y * sizeof(char*) + x * j;
		while (i < x)
		{
			rslt[j][i] = c;
			i++;
		}
		j++;
	}
	return (rslt);
}
