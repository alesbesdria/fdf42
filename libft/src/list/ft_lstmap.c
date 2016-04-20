/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeirsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:18:07 by mmeirsma          #+#    #+#             */
/*   Updated: 2016/04/12 14:18:11 by mmeirsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rslt;

	rslt = NULL;
	if (!lst || !f)
		return (NULL);
	if (lst && (rslt = ft_lstnew(lst->content, lst->content_size)) != NULL)
	{
		rslt = (*f)(rslt);
		rslt->next = ft_lstmap(lst->next, f);
	}
	if (lst && lst->next && rslt && !rslt->next)
	{
		free(rslt);
		return (NULL);
	}
	return (rslt);
}
