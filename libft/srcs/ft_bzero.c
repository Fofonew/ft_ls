
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((char*)s)[n] = 0;
}
