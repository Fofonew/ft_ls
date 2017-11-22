
void		ft_striter(char *s, void (*f)(char *))
{
	if (f)
		while (*s)
			f(s++);
}
