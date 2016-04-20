/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:38:22 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:38:25 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (ft_strlen(s))
	{
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
			i--;
		if ((str = (char *)malloc(sizeof(char) * (i + 2))) != NULL)
			ft_strcpy(str, ft_strsub(s, 0, i + 1));
		return (str);
	}
	return (ft_strdup(s));
}
