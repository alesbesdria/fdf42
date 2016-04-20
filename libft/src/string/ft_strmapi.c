/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:34:51 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:34:52 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rslt;
	unsigned int	i;

	i = ft_strlen(s);
	if ((rslt = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	rslt[i] = '\0';
	while (i--)
		rslt[i] = (*f)(i, s[i]);
	return (rslt);
}
