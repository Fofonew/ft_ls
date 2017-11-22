
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1++ == *s2++ && *(s1 - 1))
		;
	return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}
