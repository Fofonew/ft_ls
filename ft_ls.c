/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/06/05 22:59:43 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>

void	show_content(char *dir_name)
{
	struct dirent	*dirent;
	DIR				*dir;
	dir = opendir(dir_name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
		printf("%s\n", dirent->d_name);
	}
	closedir(dir);
}

void	recursive_check(char *name)
{
	struct dirent	*dirent;
	DIR				*dir;
	show_content(name);
	dir = opendir(name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
		if (dirent->d_type == 4)
		{
			printf("a");
			show_content(dirent->d_name);
			closedir(dir);
		}
	}
}

int		main(int a, char **v)
{
	//if (a == 1)
		//show_content(".");
	//else if (a == 2)
		//show_content(v[1]);
	recursive_check(".");
	return (0);
}
