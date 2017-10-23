/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/10/23 11:47:04 by doriol           ###   ########.fr       */
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

void	show_content(char *dir_name, int R, int a, int r, int l, int ot)
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

	tab = parsing(dir_name, ot);
	if (tab != NULL)
	{
		if (r)
		{
			while(tab[i])
				i++;
			i -= 1;
		}
		if (l)
		{
			lstat(tab[i], &bufc);
			printf("total %lld\n", bufc.st_blocks);
		}
		while (tab[i])
		{
			if (r)
				if (i == 0)
					break;
			if (l)
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
					if (a)
					printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
				else
					if (tab[i][0] != '.')
						printf("%u\t%lld\t%s ", buf.st_nlink, buf.st_size, time);
			}
			if (a)
				printf("%s\n", tab[i]);
			else if (R)
			{
				if (tab[i][0] != '.')
					printf("%s\n", tab[i]);
			}
			else if (tab[i][0] != '.')
				printf("%s\n", tab[i]);
			if (r)
				i--;
			else
				i++;
		}
	}
	if (R == 1)
		printf("\n");
}

void	recursive_check(char *name, int optiona, int optionr, int optionl, int optiont)
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

	show_content(name, 1, optiona, optionr, optionl, optiont);
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

				recursive_check(s, optiona, optionr, optionl, optiont);
			}
		}
	closedir(dir);
	}
}

int		main(int a, char **v)
{
	int optiona = 0;
	int optionr = 0;
	int optionR = 0;
	int optionl = 0;
	int optiont = 0;
	int secondpass = 0;
	static int e = 0;

	if (a == 1)
		show_content(".", 0, 0, 0, 0, 0);
	if (a >= 2)
	{
		int x = 1;
		while (v[x])
		{
			int y = 1;
			if (v[x][0] == '-')
			{
				while (v[x][y])
				{
					if (v[x][y] == 'R')
						optionR = 1;
					if (v[x][y] == 'r')
						optionr = 1;
					if (v[x][y] == 'a')
						optiona = 1;
					if (v[x][y] == 'l')
						optionl = 1;
					if (v[x][y] == 't')
						optiont = 1;
					if (v[x][y] != 'R' && v[x][y] != 'r' && v[x][y] != 'a' && v[x][y] != 'l' && v[x][y] != 't')
					{
						printf("ft_ls: illegal option -- %c\nusage: ft_ls [-arRlt] [file ...]\n", v[x][y]);
						exit(1);
					}
					y++;
				}
			}
			else
			{
				if (optionR == 1)
					recursive_check(v[x], optiona, optionr, optionl, optiont);
				else
				{
					if (e)
						printf("\n");
					e = 1;
					if (v[x][0] != '.')
						printf("%s:\n", v[x]);
					show_content(v[x], 0, optiona, optionr, optionl, optiont);
				}
				secondpass = 1;
			}
			x++;
		}
		if (v[x - 1][0] == '-' && optionR != 1)
			show_content(".", 0, optiona, optionr, optionl, optiont);
		else if (v[x -1][0] == '-' && optionR == 1)
			recursive_check(".", optiona, optionr, optionl, optiont);
		else if (secondpass != 1)
			show_content(v[x - 1], 0, optiona, optionr, optionl, optiont);
	}
	return (0);
}
