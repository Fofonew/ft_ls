t_display	*show5(t_option *option, t_display *display, int first)
{
	if (display->tab[display->i][0] != '.')
	{
		if (option->optionrr)
		{
			if (option->optionl)
				printf("%s\n", display->tab[display->i]);
			else if (first)
				printf("\n%s", display->tab[display->i]);
			else
			{
				printf("%s", display->tab[display->i]);
				display->check_first = 1;
			}
		}
		else
			printf("%s\n", display->tab[display->i]);
	}
	return (display);
}

t_display	*show6(t_option *option, t_display *display)
{
	if (option->optiona)
		printf("%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
	else
	{
		if (display->tab[display->i][0] != '.')
			printf("%u\t%lld\t%s ", display->buf.st_nlink, \
					display->buf.st_size, display->time);
	}
	return (display);
}

t_display	*show7(t_option *option, t_display *display, int first2)
{
	copy_master(display);
	if (first2 && !(option->optionl))
	{
		if (option->optiona)
			printf("\n%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
		else
		{
			if (display->tab[display->i][0] != '.')
				printf("\n%u\t%lld\t%s ", display->buf.st_nlink, \
						display->buf.st_size, display->time);
		}
	}
	else
	{
		show6(option, display);
		display->check_first2 = 1;
	}
	return (display);
}