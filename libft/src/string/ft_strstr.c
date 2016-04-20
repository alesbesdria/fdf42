/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:37:58 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:38:00 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2)
	{
		while (*s1)
		{
			i = 0;
			while (s1[i] == s2[i])
			{
				if (!s2[++i])
					return ((char *)s1);
			}
			s1++;
		}
		return (NULL);
	}
	return ((char *)s1);
}
