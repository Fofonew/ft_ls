
#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;

	if (!*needle)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, size))
		++haystack;
	return (ft_strncmp(haystack, needle, size)) ? NULL : (char*)haystack;
}
