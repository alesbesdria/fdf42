/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:34:43 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:34:45 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rslt;
	size_t	i;

	i = ft_strlen(s);
	if ((rslt = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	rslt[i] = '\0';
	while (i--)
		rslt[i] = (*f)(s[i]);
	return (rslt);
}
