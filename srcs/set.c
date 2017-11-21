/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:32:24 by fofow             #+#    #+#             */
/*   Updated: 2017/11/21 14:16:47 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_display	*copy(t_display *display)
{
	display->time[display->t2] = display->tmp[display->t];
	display->t2++;
	display->t++;
	return (display);
}

t_display	*set_display_time(t_option *option, t_display *display)
{
	char	*path;

	display->t = 0;
	display->t2 = 0;
	display->stop = 0;
	path = ft_strjoin(option->s, "/");
	path = ft_strjoin(path, display->tab[display->i]);
	lstat(path, &display->buf);
	display->tmp = ctime(&display->buf.st_ctime);
	display->time = ft_strnew(12);
	display->path = path;
	return (display);
}

t_display	*set_display(t_display *display, t_option *option, char *dir_name)
{
	display->i = 0;
	display->tab = parsing(dir_name, option->optiont);
	display->check_first2 = 0;
	display->check_first = 0;
	return (display);
}

t_display	*copy_master(t_display *display)
{
	while (display->tmp[display->t])
	{
		if (display->tmp[display->t] == ':')
		{
			display->stop++;
			if (display->stop == 2)
				break ;
		}
		if (display->t < 4)
			display->t++;
		else
			copy(display);
	}
	return (display);
}

void		ft_print_groups(t_display *display)
{
	display->pwd = getpwuid(display->buf.st_uid);
	display->grp = getgrgid(display->buf.st_gid);
}
