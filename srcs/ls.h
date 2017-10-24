/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:09:24 by fofow             #+#    #+#             */
/*   Updated: 2017/10/24 20:25:58 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <stdio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_parse
{
	char		*str;
	char		**tab;
	int			a;
	int			b;
}				t_parse;

typedef	struct	s_recursive
{
	int			b;
	DIR			*dir;
}				t_recursive;

typedef struct	s_display
{
	int			first;
	int			i;
	char		**tab;
	struct stat	buf;
	struct stat	bufc;
	char		*time;
	char		*tmp;
	int			t;
	int			t2;
	int			stop;
	struct dirent	*dirent;
	DIR			*dir;
}				t_display;

typedef struct	s_sort
{
	int			i;
	char		**tab;
	int			power;
}				t_sort;

typedef	struct	s_option
{
	int			optionrr;
	int			optiona;
	int			optionr;
	int			optionl;
	int			optiont;
	int			y;
}				t_option;

char			**sort_param_time(char **tab);
char			**sort_param(char **tab);
char			**parsing(char *dir_name, int t);
void			show_content(char *dir_name, int r, t_option *option);
void			recursive_check(char *name, t_option *option);
t_option		*check_option(char **v, t_option *option);
t_option		*check_option2(char **v, t_option *option, int x);
int				check_option3(char **v, t_option *option, int x);
t_recursive		*recursive2(t_recursive *recursive,
				char *name, t_option *option);

#endif
