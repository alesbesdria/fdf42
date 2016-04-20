/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:17:00 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:17:07 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstend(&((*lst)->next), new);
	else
		ft_lstadd(lst, new);
}
