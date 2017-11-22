/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:45:46 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:45:50 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*app;
	t_list	*elem;
	t_list	*prev;

	prev = NULL;
	first = NULL;
	while (lst)
	{
		app = f(lst);
		elem = ft_lstnew(app->content, app->content_size);
		if (!elem)
			return (NULL);
		if (!first)
			first = elem;
		if (prev)
			prev->next = elem;
		prev = elem;
		lst = lst->next;
	}
	return (first);
}
