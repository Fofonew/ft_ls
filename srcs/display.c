/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:16 by doriol            #+#    #+#             */
/*   Updated: 2017/10/24 21:35:33 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_content(char *dir_name, int r, t_option *option)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int				i;
	struct stat		buf;
	struct stat		bufc;
	char			*time;
	char			*tmp;
	int				t;
	int				t2;
	int				stop;
	static int		first;

	i = 0;
	tab = parsing(dir_name, option->optiont);
	if (tab != NULL)
	{
		if (option->optionr)
		{
			while (tab[i])
				i++;
			i -= 1;
		}
		if (option->optionl)
		{
			lstat(tab[i], &bufc);
			printf("total %lld\n", bufc.st_blocks);
		}
		while (tab[i])
		{
			if (option->optionl)
			{
				t = 0;
				t2 = 0;
				stop = 0;
				lstat(tab[i], &buf);
				tmp = ctime(&buf.st_ctime);
				time = ft_strnew(12);
				while (tmp[t])
				{
					if (tmp[t] == ':')
					{
						stop++;
						if (stop == 2)
							break ;
					}
					if (t < 4)
						t++;
					else
					{
						time[t2] = tmp[t];
						t2++;
						t++;
					}
				}
				if (option->optiona)
					printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
				else
				{
					if (tab[i][0] != '.')
						printf("%u\t%lld\t%s ", buf.st_nlink, \
								buf.st_size, time);
				}
			}
			if (option->optiona)
			{
				if (option->optionrr)
				{
					if (first)
						printf("\n%s", tab[i]);
					else
					{
						printf("%s", tab[i]);
						first = 1;
					}
				}
				else
					printf("%s\n", tab[i]);
			}
			else if (r)
			{
				if (tab[i][0] != '.')
				{
					if (option->optionrr)
					{
						if (first)
							printf("\n%s", tab[i]);
						else
						{
							printf("%s", tab[i]);
							first = 1;
						}
					}
					else
						printf("%s\n", tab[i]);
				}
			}
			else if (tab[i][0] != '.')
			{
				if (option->optionrr)
				{
					if (first)
						printf("\n%s", tab[i]);
					else
					{
						printf("%s", tab[i]);
						first = 1;
					}
				}
				else
					printf("%s\n", tab[i]);
			}
			if (option->optionr)
				if (i == 0)
					break ;
			if (option->optionr)
				i--;
			else
				i++;
		}
	}
	if (r == 1)
		printf("\n");
}

/*t_display	*show_content_master(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionl)
		show_content5(dir_name, r, display, option);
	if (option->optiona)
		show_content4(dir_name, r, display, option);
	else if (r)
		show_content3(dir_name, r, display, option);
	else if (display->tab[display->i][0] != '.')
		show_content2(dir_name, r, display, option);
	if (option->optionr)
		if (display->i == 0)
		{
			display->breakk = 1;
			return (display);
		}
	if (option->optionr)
		display->i--;
	else
		display->i++;
	return (display);
}

t_display	*show_content6(char *dir_name, int r, t_display *display, t_option *option)
{
	if (display->tmp[display->t] == ':')
	{
		display->stop++;
		if (display->stop == 2)
		{
			display->breakk = 1;
			return (display);
		}
	}
	if (display->t < 4)
		display->t++;
	else
	{
		display->time[display->t2] = display->tmp[display->t];
		display->t2++;
		display->t++;
	}
	return (display);
}

t_display	*show_content5(char *dir_name, int r, t_display *display, t_option *option)
{
	display->t = 0;
	display->t2 = 0;
	display->stop = 0;
	lstat(display->tab[display->i], &display->buf);
	display->tmp = ctime(&display->buf.st_ctime);
	display->time = ft_strnew(12);
	while (display->tmp[display->t])
	{
		show_content6(dir_name, r, display, option);
		if (display->breakk == 1)
			break ;
	}
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

t_display	*show_content4(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*show_content3(char *dir_name, int r, t_display *display, t_option *option)
{
	if (display->tab[display->i][0] != '.')
	{
		if (option->optionrr)
		{
			if (display->first)
				printf("\n%s", display->tab[display->i]);
			else
			{
				printf("%s", display->tab[display->i]);
				display->first = 1;
			}
		}
		else
			printf("%s\n", display->tab[display->i]);
	}
	return (display);
}

t_display	*show_content2(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*set_display(t_display *display, char *dir_name, t_option *option)
{
	display->i = 0;
	display->tab = parsing(dir_name, option->optiont);
	display->breakk = 0;
	return (display);
}

void		show_content(char *dir_name, int r, t_option *option)
{
	t_display			*display;

	display = malloc(sizeof(t_display));
	set_display(display, dir_name, option);
	if (display->tab != NULL)
	{
		if (option->optionr)
		{
			while (display->tab[display->i])
				display->i++;
			display->i -= 1;
		}
		if (option->optionl)
		{
			lstat(display->tab[display->i], &display->bufc);
			printf("total %lld\n", display->bufc.st_blocks);
		}
		while (display->tab[display->i])
		{
			show_content_master(dir_name, r, display, option);
			if (display->breakk == 1)
				break ;
		}
	}
	if (r == 1)
		printf("\n");
}*/