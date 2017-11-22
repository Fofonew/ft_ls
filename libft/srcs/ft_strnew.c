
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (i < (int)size)
		new[i++] = '\0';
	return (new);
}
