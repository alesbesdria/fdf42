/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:20:13 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:20:15 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		if (*((unsigned char *)src - 1) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
