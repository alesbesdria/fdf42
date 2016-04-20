/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:38:06 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:38:08 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rslt;

	rslt = NULL;
	if (ft_strlen(s) >= start)
	{
		if ((rslt = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_strncpy(rslt, (s + start), len);
		rslt[len] = '\0';
	}
	return (rslt);
}
