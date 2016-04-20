/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:40:14 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:40:17 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wtoc(wchar_t w)
{
	char	str[5];
	int		n;

	n = 3;
	ft_bzero((void*)str, 5);
	if ((w > 55295 && w < 57344) || w > 1114111)
		return (NULL);
	if (!(w >> 7))
		str[n] = (unsigned char)(w & 127);
	else
		str[n--] = (unsigned char)((w & 63) | 128);
	if (!(w >> 11) && (w >> 7))
		str[n] = (unsigned char)((w >> 6 & 31) | 192);
	else if ((w >> 11))
		str[n--] = (unsigned char)((w >> 6 & 63) | 128);
	if (!(w >> 16) && (w >> 11))
		str[n] = (unsigned char)((w >> 12 & 15) | 224);
	else if ((w >> 16))
	{
		str[n--] = (unsigned char)((w >> 12 & 63) | 128);
		str[n] = (unsigned char)((w >> 18 & 7) | 240);
	}
	return (ft_strdup(&str[n]));
}
