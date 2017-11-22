
#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	size_t			s;

	s = ft_strlen(needle);
	i = 0;
	while (haystack[i] && ft_strncmp(haystack + i, needle, s))
		++i;
	return ((haystack[i] && n >= i + s) || !*needle) ?
	(char*)(haystack + i) : 0;
}
