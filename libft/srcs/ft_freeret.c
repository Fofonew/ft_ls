
#include "libft.h"

int			ft_freeret(void *p, int r)
{
	free(p);
	return (r);
}
