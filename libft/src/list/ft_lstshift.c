/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:18:36 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:18:39 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstshift(t_list **lst)
{
	t_list	*rslt;

	rslt = *lst;
	if (*lst)
	{
		*lst = (*lst)->next;
		rslt->next = NULL;
	}
	return (rslt);
}
