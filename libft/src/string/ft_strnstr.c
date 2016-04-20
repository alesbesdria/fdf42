/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:36:40 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:36:42 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s;
	int		i;

	s = ft_strdup(s1);
	s[n] = '\0';
	if (ft_strstr(s, s2) == NULL)
		return (NULL);
	i = ft_strlen(s) - ft_strlen(ft_strstr(s, s2));
	return ((char *)(s1 + i));
}
