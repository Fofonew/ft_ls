
#include <string.h>

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (*src && j != n)
		dest[i + j++] = *src++;
	dest[i + j] = '\0';
	return (dest);
}
