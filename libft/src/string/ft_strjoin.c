/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:33:28 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:33:32 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if ((s = ft_strnew((size_t)ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (s);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
