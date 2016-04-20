/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:23:49 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:23:53 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_atoi_base(const char *str, int base)
{
	size_t		rslt;
	int			temp;

	rslt = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str)
	{
		temp = 126;
		if ((*str >= '0' && *str <= '0' + base - 1) && base <= 10)
			temp = *str - 48;
		if ((*str >= '0' && *str <= '9') && base > 10)
			temp = *str - 48;
		if ((*str >= 'A' && *str <= 'A' + base - 11) && base <= 36)
			temp = *str - 55;
		if ((*str >= 'a' && *str <= 'a' + base - 11) && base <= 36)
			temp = *str - 87;
		if (temp != 126)
			rslt = rslt * base + temp;
		else
			return (rslt);
		str++;
	}
	return (rslt);
}
