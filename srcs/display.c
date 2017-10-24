/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:16 by doriol            #+#    #+#             */
/*   Updated: 2017/10/24 19:31:12 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_content(char *dir_name, int r, t_option *option)
{
	//struct dirent	*dirent;
	//DIR				*dir;
	//char			**tab;
	//int				i;
	//struct stat		buf;
	//struct stat		bufc;
	//char			*time;
	//char			*tmp;
	//int				t;
	//int				t2;
	//int				stop;
	//static int		first;
	t_display			*display;

	display = malloc(sizeof(t_display));
	display->i = 0;
	display->tab = parsing(dir_name, option->optiont);
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
			lstat(display->tab[display->i], display->&bufc);
			printf("total %lld\n", display->bufc.st_blocks);
		}
		while (display->tab[display->i])
		{
			if (option->optionl)
			{
				display->t = 0;
				display->t2 = 0;
				display->stop = 0;
				lstat(display->tab[display->i], display->&buf);
				display->tmp = ctime(display->&buf.st_ctime);
				display->time = ft_strnew(12);
				while (display->tmp[display->t])
				{
					if (display->tmp[display->t] == ':')
					{
						display->stop++;
						if (display->stop == 2)
							break ;
					}
					if (display->t < 4)
						display->t++;
					else
					{
						display->time[display->t2] = display->tmp[display->t];
						display->t2++;
						display->t++;
					}
				}
				if (option->optiona)
					printf("%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
				else
				{
					if (display->tab[display->i][0] != '.')
						printf("%u\t%lld\t%s ", display->buf.st_nlink, \
							display->buf.st_size, display->time);
				}
			}
			if (option->optiona)
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
			else if (r)
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
			}
			else if (display->tab[display->i][0] != '.')
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
			if (option->optionr)
				if (display->i == 0)
					break ;
			if (option->optionr)
				display->i--;
			else
				display->i++;
		}
	}
	if (r == 1)
		printf("\n");
}
