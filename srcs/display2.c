/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:31:55 by fofow             #+#    #+#             */
/*   Updated: 2017/10/25 18:41:55 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		print_rights(t_display *file)
{
	if (S_ISREG((*file).buf.st_mode))
		write(1, "-", 1);
	else if (S_ISDIR((*file).buf.st_mode))
		write(1, "d", 1);
	else if (S_ISCHR((*file).buf.st_mode))
		write(1, "c", 1);
	else if (S_ISBLK((*file).buf.st_mode))
		write(1, "b", 1);
	else if (S_ISFIFO((*file).buf.st_mode))
		write(1, "p", 1);
	else if (S_ISLNK((*file).buf.st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK((*file).buf.st_mode))
		write(1, "s", 1);
	write(1, (*file).buf.st_mode & S_IRUSR ? "r" : "-", 1);
	write(1, (*file).buf.st_mode & S_IWUSR ? "w" : "-", 1);
	write(1, (*file).buf.st_mode & S_IXUSR ? "x" : "-", 1);
	write(1, (*file).buf.st_mode & S_IRGRP ? "r" : "-", 1);
	write(1, (*file).buf.st_mode & S_IWGRP ? "w" : "-", 1);
	write(1, (*file).buf.st_mode & S_IXGRP ? "x" : "-", 1);
	write(1, (*file).buf.st_mode & S_IROTH ? "r" : "-", 1);
	write(1, (*file).buf.st_mode & S_IWOTH ? "w" : "-", 1);
	write(1, (*file).buf.st_mode & S_IXOTH ? "x" : "-", 1);
}

t_display	*show5(t_option *option, t_display *display, int first)
{
	if (display->tab[display->i][0] != '.')
	{
		if (option->optionrr)
		{
			if (option->optionl)
				printf("%s\n", display->tab[display->i]);
			else if (first)
				printf("\n%s", display->tab[display->i]);
			else
			{
				printf("%s", display->tab[display->i]);
				display->check_first = 1;
			}
		}
		else
			printf("%s\n", display->tab[display->i]);
	}
	return (display);
}

t_display	*show6(t_option *option, t_display *display)
{

	if (option->optiona)
	{
		print_rights(display);
		printf("\t%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
	}
	else
	{
		if (display->tab[display->i][0] != '.')
		{
			print_rights(display);
			printf("\t%u\t%lld\t%s ", display->buf.st_nlink, \
					display->buf.st_size, display->time);
		}
	}
	return (display);
}

t_display	*show7(t_option *option, t_display *display, int first2)
{
	copy_master(display);
	if (first2 && !(option->optionl))
	{
		if (option->optiona)
			printf("\n%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
		else
		{
			if (display->tab[display->i][0] != '.')
				printf("\n%u\t%lld\t%s ", display->buf.st_nlink, \
						display->buf.st_size, display->time);
		}
	}
	else
	{
		show6(option, display);
		display->check_first2 = 1;
	}
	return (display);
}

t_display	*counter(t_display *display, t_option *option)
{
	if (option->optionr)
		display->i--;
	else
		display->i++;
	return (display);
}
