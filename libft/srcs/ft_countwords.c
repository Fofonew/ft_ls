
int		ft_countwords(char const *s, char c)
{
	int count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c && word)
			word = 0;
		s++;
	}
	return (count);
}
