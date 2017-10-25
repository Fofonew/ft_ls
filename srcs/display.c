/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:16 by doriol            #+#    #+#             */
/*   Updated: 2017/10/25 13:23:12 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_display	*show6(t_option *option, t_display *display)
{
	if (option->optiona)
		printf("%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
	else
	{
		if (display->tab[display->i][0] != '.')
			printf("%u\t%lld\t%s ", display->buf.st_nlink, \
					display->buf.st_size, display->time);
	}
	return (display);
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

t_display	*show2(t_option *option, t_display *display)
{
	static int	first3;

	if (option->optionr)
	{
		while (display->tab[display->i])
			display->i++;
		display->i -= 1;
	}
	if (option->optionl)
	{
		lstat(display->tab[display->i], &display->bufc);
		if (first3)
			printf("\ntotal %lld\n", display->bufc.st_blocks);
		else
		{
			printf("total %lld\n", display->bufc.st_blocks);
			first3 = 1;
		}
	}
	return (display);
}

t_display	*show4(t_option *option, t_display *display, int first)
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
	return (display);
}

t_display	*show3(t_option *option, t_display *display, int first2)
{
	if (option->optionrr)
	{
		if (option->optionl && option->optiona)
			printf("%s\n", display->tab[display->i]);
		else if (option->optionl)
			printf("%s", display->tab[display->i]);
		else if (first2)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->check_first2 = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*copy(t_display *display)
{
	display->time[display->t2] = display->tmp[display->t];
	display->t2++;
	display->t++;
	return (display);
}

t_display	*set_display_time(t_display *display)
{
	display->t = 0;
	display->t2 = 0;
	display->stop = 0;
	lstat(display->tab[display->i], &display->buf);
	display->tmp = ctime(&display->buf.st_ctime);
	display->time = ft_strnew(12);

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

void		show_content(char *dir_name, int r, t_option *option)
{
	t_display		*display;
	static int		first;
	static int		first2;

	display = malloc(sizeof(t_display));
	set_display(display, option, dir_name);
	if (display->tab != NULL)
	{
		show2(option, display);		
		while (display->tab[display->i])
		{
			if (option->optionl)
			{
				set_display_time(display);
				show7(option, display, first2);
				if(display->check_first2)
					first2 = display->check_first2;
			}
			if (option->optiona)
				show3(option, display, first2);
			if (display->check_first2)
				first2 = display->check_first2;
			if (r && !(option->optiona))
				show5(option, display, first);
			if (display->check_first)
				first = display->check_first;
			else if (display->tab[display->i][0] != '.' && !(option->optiona) && !(r))
				show4(option, display, first);
			if (display->check_first)
				first = display->check_first;
			if (option->optionr)
				if (display->i == 0)
					break ;
			if (option->optionr)
				display->i--;
			else
				display->i++;
		}
	}
	if (r && !(option->optionl))
		printf("\n");
}
