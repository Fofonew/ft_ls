
#include "libft.h"

int			ft_atoi(const char *str)
{
	int neg;
	int	nbr;

	nbr = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-' ? -1 : 1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10 + *str++ - '0');
	return (neg * nbr);
}
