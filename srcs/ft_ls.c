/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/06/13 00:13:01 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>
#include "libft.h"

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
	int a = 0;
	dir = opendir(dir_name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
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
	return(tab);
}



void	show_content(char *dir_name, int R, int a, int r)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int i = 0;
	tab = parsing(dir_name);
	//dir = opendir(dir_name);
	//while (1)
	//{
	//	dirent = readdir(dir);
	//	if (dirent == NULL)
	//		break;
	//	else if (R)
	//	{
	//		if (dirent->d_name[0] != '.')
	//			printf("%s\n", dirent->d_name);
	//	}
	//	else if (a)
	//		printf("%s\n", dirent->d_name);
	//	else if (dirent->d_name[0] != '.')
	//		printf("%s\n", dirent->d_name);
	//}
	//closedir(dir);
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
	if (R == 1)
		printf("\n");
}

void	recursive_check(char *name)
{
	struct dirent	*dirent;
	DIR				*dir;
	static int		a;
	char *s;

	if (a)
		printf("%s:\n", s);
	a = 1;
	show_content(name, 1, 0, 0);
	dir = opendir(name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
		if (dirent->d_type == 4 && dirent->d_name[0] != '.')
		{
			s = ft_strjoin(name, "/");
			s = ft_strjoin(s, dirent->d_name);
			recursive_check(s);
		}
	}

	closedir(dir);
}

int		main(int a, char **v)
{
	if (a == 1)
	{
		show_content(".", 0, 0, 0);
		//parsing(".");
	}
	if (a >= 2)
	{
		if (v[1][0] == '-' && v[1][1] == 'R')
		{

			if (a != 3)
				recursive_check(".");
			else
				recursive_check(v[2]);
		}
		else if (v[1][0] == '-' && v[1][1] == 'a')
		{
			if (a != 3)
				show_content(".", 0, 1, 0);
			else
				show_content(v[2], 0, 1, 0);
		}
		else if (v[1][0] == '-' && v[1][1] == 'r')
		{
			if (a != 3)
				show_content(".", 0, 0, 1);
			else
				show_content(v[2], 0, 0, 1);
		}
		else if (v[1][0] == '-' && (v[1][1] != 'l' && v[1][1] != 'R' 
			&& v[1][1] != 'a' && v[1][1] != 'r' && v[1][1] != 't'))
		{
			ft_putstr("Error : option not supported\n");
			return (1);
		}
		else
			show_content(v[1], 0, 0, 0);
	}
	return (0);
}
