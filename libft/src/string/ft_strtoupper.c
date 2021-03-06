/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:38:12 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:38:14 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strtoupper(char *str)
{
	while (str && *str)
	{
		*str = (char)ft_toupper((int)(*str));
		str++;
	}
}
