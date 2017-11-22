
#include "libft.h"

void		ft_lstpush(t_list **alst, t_list *new)
{
	if (*alst)
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
	}
	else
		*alst = new;
}
