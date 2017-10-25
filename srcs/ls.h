/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:09:24 by fofow             #+#    #+#             */
/*   Updated: 2017/10/25 11:35:05 by fofow            ###   ########.fr       */
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

typedef struct		s_parse
{
	char			*str;
	char			**tab;
	int				a;
	int				b;
}					t_parse;

typedef	struct		s_recursive
{
	int				b;
	DIR				*dir;
}					t_recursive;

typedef struct		s_display
{
	int				i;
	char			**tab;
	struct stat		buf;
	struct stat		bufc;
	char			*time;
	char			*tmp;
	int				t;
	int				t2;
	int				stop;
	struct dirent	*dirent;
	DIR				*dir;
	int				breakk;
	int				check_first2;
	int				check_first;
}					t_display;

typedef struct		s_sort
{
	int				i;
	char			**tab;
	int				power;
}					t_sort;

typedef	struct		s_option
{
	int				optionrr;
	int				optiona;
	int				optionr;
	int				optionl;
	int				optiont;
	int				y;
}					t_option;

t_display			*counter(t_display *display, t_option *option);
t_display			*show8(t_option *option, t_display *display, int r);
t_display			*show6(t_option *option, t_display *display);
t_display			*show5(t_option *option, t_display *display, int first);
t_display			*show2(t_option *option, t_display *display);
t_display			*show4(t_option *option, t_display *display, int first);
t_display			*show3(t_option *option, t_display *display, int first2);
t_display			*copy(t_display *display);
t_display			*set_display_time(t_display *display);
t_display			*set_display(t_display *display, t_option *option, char *dir_name);
t_display			*copy_master(t_display *display);
t_display			*show7(t_option *option, t_display *display, int first2);
char				**sort_param_time(char **tab);
char				**sort_param(char **tab);
char				**parsing(char *dir_name, int t);
void				show_content(char *dir_name, int r, t_option *option);
void				recursive_check(char *name, t_option *option);
t_option			*check_option(char **v, t_option *option);
t_option			*check_option2(char **v, t_option *option, int x);
int					check_option3(char **v, t_option *option, int x);
t_recursive			*recursive2(t_recursive *recursive,
					char *name, t_option *option);

#endif
