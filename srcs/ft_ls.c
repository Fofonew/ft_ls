/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/10/24 00:21:48 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "ls.h"


char	**sort_param_time(char **tab)
{
	int		i;
	char	*tmp;
	int		power;
	struct stat buf;
	struct stat buf2;

	power = 1;
	while (power)
	{
		power = 0;
		i = 1;
		while (tab[i])
		{

			if (tab[i + 1] != '\0')
			{

				stat(tab[i], &buf);
				stat(tab[i + 1], &buf2);
				if ((buf.st_mtime) < (buf2.st_mtime))
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					power = 1;
				}
			}
			i++;
		}
	}
	return (tab);
}

char	**sort_param(char **tab)
{
	int		i;
	char	*tmp;
	int		power;

	power = 1;
	while (power)
	{
		power = 0;
		i = 1;
		while (tab[i])
		{
			if (tab[i + 1] != '\0')
				if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				{
					tmp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = tmp;
					power = 1;
				}
			i++;
		}
	}
	return (tab);
}

char	**parsing(char *dir_name, int t)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			*str = NULL;
	char			**tab;
	int				a = 0;
	int				b = 0;
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		perror(dir_name);
		b = 1;
	}
	if (b != 1)
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if (a == 0)
				str = ft_strdup(dirent->d_name);
			if (a == 1)
			{
				str = ft_strjoin(str, "%");
				str = ft_strjoin(str, dirent->d_name);
			}
			a = 1;
		}
		tab = ft_strsplit(str, '%');
		if (t)
			sort_param_time(tab);
		else
			sort_param(tab);
		closedir(dir);
		return(tab);
	}
	return (NULL);
}

void	show_content(char *dir_name, int R, t_option *option)
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
	int 			stop;

	i = 0;

	tab = parsing(dir_name, option->optiont);
	if (tab != NULL)
	{
		if (option->optionr)
		{
			while(tab[i])
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
			if (option->optionr)
				if (i == 0)
					break;
			if (option->optionl)
			{
				t = 0;
				t2 = 0;
				stop = 0;
				lstat(tab[i], &buf);
				tmp = ctime(&buf.st_ctime);
				time = ft_strnew(12);
				while(tmp[t])
				{
					if (tmp[t] == ':')
					{
						stop++;
						if (stop == 2)
							break;
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
					if (tab[i][0] != '.')
						printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
			}
			if (option->optiona)
				printf("%s\n", tab[i]);
			else if (R)
			{
				if (tab[i][0] != '.')
					printf("%s\n", tab[i]);
			}
			else if (tab[i][0] != '.')
				printf("%s\n", tab[i]);
			if (option->optionr)
				i--;
			else
				i++;
		}
	}
	if (R == 1)
		printf("\n");
}

void	recursive_check(char *name, t_option *option)
{
	struct dirent	*dirent;
	DIR				*dir;
	static int		a;
	char 			*s;
	int				b;

	b = 0;
	if (a)
		printf("%s:\n", name);
	a = 1;

	show_content(name, 1, option);
	dir = opendir(name);
	if (dir == NULL)
	{
		perror("");
		b = 1;
	}
	if (b != 1)
	{
		while ((dirent = readdir(dir)) != NULL)
		{
			if (dirent->d_type == 4 && dirent->d_name[0] != '.')
			{
				s = ft_strjoin(name, "/");
				s = ft_strjoin(s, dirent->d_name);
				recursive_check(s, option);
			}
		}
		closedir(dir);
	}
}

t_option	*set(t_option *option)
{
	option->optionR = 0;
	option->optiona = 0;
	option->optionr = 0;
	option->optionl = 0;
	option->optiont = 0;
	return (option);
}

int		main(int a, char **v)
{
	t_option	*option;

	option = malloc(sizeof(t_option));
	set(option);
	if (a == 1)
		show_content(".", 0, option);
	if (a >= 2)
		check_option(v, option);
	return (0);
}

t_option	*check_option2(char **v, t_option *option, int x)
{
	int y;

	y = 1;
	while (v[x][y])
	{
		if (v[x][y] == 'R')
			option->optionR = 1;
		if (v[x][y] == 'r')
			option->optionr = 1;
		if (v[x][y] == 'a')
			option->optiona = 1;
		if (v[x][y] == 'l')
			option->optionl = 1;
		if (v[x][y] == 't')
			option->optiont = 1;
		if (v[x][y] != 'R' && v[x][y] != 'r' && v[x][y] != 'a' &&
				v[x][y] != 'l' && v[x][y] != 't')
		{
			printf("ft_ls: illegal option -- %c\nusage: ft_ls [-arRlt] [file ...]\n", v[x][y]);
			exit(1);
		}
		y++;
	}
	return (option);
}

int		checkoption3(char **v, t_option *option, int x, int e)
{
	static	int	secondpass;
	secondpass = 0;
	if (option->optionR == 1)
		recursive_check(v[x], option);
	else
	{
		if (e)
			printf("\n");
		e = 1;
		if (v[x][0] != '.')
			printf("%s:\n", v[x]);
		show_content(v[x], 0, option);
	}
	secondpass = 1;
	return (e);
}

t_option	*check_option(char **v, t_option *option)
{
	int 		x;
	int			secondpass;
	static int	e;

	x = 1;
	secondpass = 0;
	e = 0;
	while (v[x])
	{
		int y = 1;
		if (v[x][0] == '-')
			check_option2(v, option, x);
		else
			checkoption3(v, option, x, e);
		x++;
	}
	if (v[x - 1][0] == '-' && option->optionR != 1)
		show_content(".", 0, option);
	else if (v[x -1][0] == '-' && option->optionR == 1)
		recursive_check(".", option);
	else if (secondpass != 1)
		show_content(v[x - 1], 0, option);
	return (option);
}
