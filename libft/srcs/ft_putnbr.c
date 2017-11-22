
#include "libft.h"

void		ft_putnbr(int n)
{
	unsigned int	n2;

	if (n < 0)
		ft_putchar('-');
	n2 = (n < 0 ? -n : n);
	if (n2 >= 10)
	{
		ft_putnbr(n2 / 10);
		ft_putchar(n2 % 10 + '0');
	}
	else
		ft_putchar(n2 + '0');
}
