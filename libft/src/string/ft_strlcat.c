/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:33:36 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:33:42 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst + 1 < size)
		ft_strncat(dst, src, size - 1 - ldst);
	return (ldst > size ? lsrc + size : ldst + lsrc);
}
