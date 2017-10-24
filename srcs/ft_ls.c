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

#include "ls.h"

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