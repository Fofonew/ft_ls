
#include <string.h>

void		*ft_memset(void *str, int c, size_t n)
{
	while (n--)
		((char*)str)[n] = c;
	return (str);
}
