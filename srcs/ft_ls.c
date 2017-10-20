/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/08/15 00:36:58 by fofow            ###   ########.fr       */
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
	struct stat *buf;
	struct stat *buf2;
	buf = malloc(sizeof(stat));
	buf2 = malloc(sizeof(stat));

	power = 1;
	while (power)
	{
		power = 0;
		i = 1;
		while (tab[i])
		{

			if (tab[i + 1] != '\0')
			{

				stat(tab[i], buf);
				stat(tab[i + 1], buf2);
				if ((buf->st_mtime) < (buf2->st_mtime))
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

char	**parsing(char *dir_name)
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
		sort_param(tab);
		closedir(dir);
		return(tab);
	}
	return (NULL);
}

void	show_content(char *dir_name, int R, int a, int r, int l)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int				i;
	struct stat		*buf;

	i = 0;
	tab = parsing(dir_name);
	if (tab != NULL)
	{
		if (r)
		{
			while(tab[i])
				i++;
			i -= 1;
		}
		while (tab[i])
		{
			if (r)
				if (i == 0)
					break;
			if (l)
			{
				buf = malloc(sizeof(stat));
				stat(tab[i], buf);
				printf("%s ", ctime(&buf->st_mtime));
				free(buf);
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

void	recursive_check(char *name, int optiona, int optionr, int optionl)
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

	show_content(name, 1, optiona, optionr, optionl);
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

				recursive_check(s, optiona, optionr, optionl);
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
	int secondpass = 0;
	static int e = 0;

	if (a == 1)
		show_content(".", 0, 0, 0, 0);
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
					recursive_check(v[x], optiona, optionr, optionl);
				else
				{
					if (e)
						printf("\n");
					e = 1;
					printf("%s:\n", v[x]);
					show_content(v[x], 0, optiona, optionr, optionl);
				}
				secondpass = 1;
			}
			x++;
		}
		if (v[x - 1][0] == '-' && optionR != 1)
			show_content(".", 0, optiona, optionr, optionl);
		else if (v[x -1][0] == '-' && optionR == 1)
			recursive_check(".", optiona, optionr, optionl);
		else if (secondpass != 1)
			show_content(v[x - 1], 0, optiona, optionr, optionl);
	}
	return (0);
}
