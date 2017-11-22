
#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	i;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (*s)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
