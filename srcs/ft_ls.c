/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 09:16:35 by fofow             #+#    #+#             */
/*   Updated: 2017/10/24 19:08:29 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_recursive	*recursive2(t_recursive *recursive, char *name, t_option *option)
{
	static int	a;

	if (a)
		printf("\n%s:", name);
	a = 1;
	show_content(name, 1, option);
	recursive->dir = opendir(name);
	if (recursive->dir == NULL)
	{
		perror("");
		recursive->b = 1;
	}
	return (recursive);
}

void		recursive_check(char *name, t_option *option)
{
	struct dirent	*dirent;
	t_recursive		*recursive;
	char			*s;

	recursive = malloc(sizeof(t_recursive));
	recursive->b = 0;
	recursive2(recursive, name, option);
	if (recursive->b != 1)
	{
		while ((dirent = readdir(recursive->dir)) != NULL)
		{
			if (dirent->d_type == 4 && dirent->d_name[0] != '.')
			{
				s = ft_strjoin(name, "/");
				s = ft_strjoin(s, dirent->d_name);
				recursive_check(s, option);
			}
		}
		closedir(recursive->dir);
	}
}

t_option	*set(t_option *option)
{
	option->optionrr = 0;
	option->optiona = 0;
	option->optionr = 0;
	option->optionl = 0;
	option->optiont = 0;
	return (option);
}

int			main(int a, char **v)
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
