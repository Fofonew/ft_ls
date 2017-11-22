
#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char*)malloc(sizeof(char) * (n + 1));
	if (!cpy)
		return (NULL);
	while (n-- > 0)
		cpy[i++] = *s1++;
	cpy[i] = '\0';
	return (cpy);
}
