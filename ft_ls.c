/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/06/04 10:10:52 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>

void	ft_ls(char *name)
{
	struct dirent *dirent;
	DIR *dir;
	dir = opendir(name);
	while (1)
	{
		dirent = readdir(dir);
		if (dirent == NULL)
			break;
		printf("%s\n", dirent->d_name);
	}
	closedir(dir);
}

int		main(int a, char **v)
{
	if (a == 1)
		ft_ls(".");
	else if (a == 2)
		ft_ls(v[1]);
	return 0;
}
