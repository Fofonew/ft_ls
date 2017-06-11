/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/06/12 01:39:31 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>
#include "libft.h"

void	show_content(char *dir_name, int R, int a)
{
	struct dirent	*dirent;
	DIR				*dir;
	dir = opendir(dir_name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
		else if (R)
		{
			if (dirent->d_name[0] != '.')
				printf("%s\n", dirent->d_name);
		}
		else if (a)
			printf("%s\n", dirent->d_name);
		else if (dirent->d_name[0] != '.')
			printf("%s\n", dirent->d_name);
	}
	if (R == 1)
		printf("\n");
	closedir(dir);
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
	show_content(name, 1, 0);
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
		show_content(".", 0, 0);
	else if (a >= 2)
	{
		if (v[1][0] == '-' && v[1][1] == 'R')
		{
			if (a != 3)
				recursive_check(".");
			else
				recursive_check(v[2]);
		}
		if (v[1][0] == '-' && v[1][1] == 'a')
		{
			if (a != 3)
				show_content(".", 0, 1);
			else
				show_content(v[2], 0, 1);
		}
		else
			show_content(v[1], 0, 0);
	}
	return (0);
}
