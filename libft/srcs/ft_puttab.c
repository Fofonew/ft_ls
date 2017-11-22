
#include "libft.h"

void		ft_puttab(char **tab)
{
	if (*tab)
		while (*tab)
		{
			ft_putstr(*tab++);
			ft_putchar('\n');
		}
}
