
#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	while (*s)
		ret[i++] = f(*s++);
	ret[i] = '\0';
	return (ret);
}
