
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)))
		while (size--)
			((char*)ptr)[size] = 0;
	return (ptr);
}
