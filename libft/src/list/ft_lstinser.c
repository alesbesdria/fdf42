/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:16:22 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:16:27 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstinser(t_list **lst, t_list *src, size_t n)
{
	if (n && *lst)
		return (ft_lstinser(&((*lst)->next), src, n - 1) + 1);
	src->next = *lst;
	*lst = src;
	return (0);
}
