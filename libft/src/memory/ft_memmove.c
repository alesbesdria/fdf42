/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:21:38 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:21:41 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		while (len--)
		{
			*((char *)dst + len) = *((char *)src + len);
		}
	}
	return (dst);
}
