/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:07:31 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:07:43 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_boardprint(char **tab, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putchar(tab[j][i]);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
}
