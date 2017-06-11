/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 10:35:29 by doriol            #+#    #+#             */
/*   Updated: 2017/04/15 10:37:15 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	fresh = NULL;
	if (lst && f)
	{
		fresh = (*f)(lst);
		fresh->next = ft_lstmap(lst->next, (*f));
		return (fresh);
	}
	return (NULL);
}
