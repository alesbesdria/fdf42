/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:36:47 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:36:48 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s);
	while (l && s[l] != (char)c)
		l--;
	if (s[l] == (char)c)
		return ((char *)(s + l));
	else
		return (NULL);
}
