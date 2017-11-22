
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s) + 1;
	while (i && s[--i] != c)
		;
	return (s[i] == c) ? (char*)s + i : 0;
}
