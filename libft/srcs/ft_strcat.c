
char				*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		++i;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
