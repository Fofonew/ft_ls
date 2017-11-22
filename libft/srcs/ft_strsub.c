
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (len-- > 0)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
