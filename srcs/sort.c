/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:41:36 by doriol            #+#    #+#             */
/*   Updated: 2017/11/21 13:12:25 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_sort	*sort_param_time2(t_sort *sort)
{
	struct stat	buf;
	struct stat	buf2;
	char		*tmp;

	if (sort->tab[sort->i + 1] != '\0')
	{
		stat(sort->tab[sort->i], &buf);
		stat(sort->tab[sort->i + 1], &buf2);
		if ((buf.st_ctime) < (buf2.st_ctime))
		{
			tmp = sort->tab[sort->i];
			sort->tab[sort->i] = sort->tab[sort->i + 1];
			sort->tab[sort->i + 1] = tmp;
			sort->power = 1;
		}
	}
	sort->i++;
	return (sort);
}

char	**sort_param_time(char **tab)
{
	t_sort			*sort;

	sort = malloc(sizeof(t_sort));
	sort->power = 1;
	sort->tab = tab;
	while (sort->power)
	{
		sort->power = 0;
		sort->i = 1;
		while (sort->tab[sort->i])
			sort_param_time2(sort);
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

t_parse	*parse2(t_parse *parse, DIR *dir, struct dirent *dirent, int t)
{
	while ((dirent = readdir(dir)) != NULL)
	{
		if (parse->a == 0)
			parse->str = ft_strdup(dirent->d_name);
		if (parse->a == 1)
		{
			parse->str = ft_strjoin(parse->str, "%");
			parse->str = ft_strjoin(parse->str, dirent->d_name);
		}
		parse->a = 1;
	}
	parse->tab = ft_strsplit(parse->str, '%');
	if (t)
		sort_param_time(parse->tab);
	else
		sort_param(parse->tab);
	return (parse);
}

char	**parsing(char *dir_name, int t)
{
	struct dirent	*dirent;
	DIR				*dir;
	t_parse			*parse;

	parse = malloc(sizeof(t_parse));
	dirent = NULL;
	parse->a = 0;
	parse->b = 0;
	parse->str = NULL;
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		perror(dir_name);
		parse->b = 1;
	}
	if (parse->b != 1)
	{
		parse2(parse, dir, dirent, t);
		closedir(dir);
		return (parse->tab);
	}
	return (NULL);
}
