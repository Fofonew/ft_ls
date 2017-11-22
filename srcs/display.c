/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:16 by doriol            #+#    #+#             */
/*   Updated: 2017/11/22 10:47:09 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_display	*show2(t_option *option, t_display *display)
{
	static int	first3;
	char		*path;

	if (option->optionr)
	{
		while (display->tab[display->i])
			display->i++;
		display->i -= 1;
	}
	if (option->optionl)
	{
		path = ft_strjoin(option->s, "/");
		path = ft_strjoin(path, display->tab[display->i]);
		lstat(path, &display->bufc);
		if (first3)
			print_total(display, option->s, '\n');
		else
		{
			print_total(display, display->tab[display->i], 0);
			first3 = 1;
		}
	}
	return (display);
}

t_display	*show3(t_option *option, t_display *display, int first2)
{
	if (option->optionrr)
	{
		if (option->optionl && option->optiona)
			ft_printf("%s\n", display->tab[display->i]);
		else if (option->optionl)
			ft_printf("%s", display->tab[display->i]);
		else if (first2)
			ft_printf("\n%s", display->tab[display->i]);
		else
		{
			ft_printf("%s", display->tab[display->i]);
			display->check_first2 = 1;
		}
	}
	else
		ft_printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*show4(t_option *option, t_display *display, int first)
{
	if (option->optionrr)
	{
		if (option->optionl)
			ft_printf("%s\n", display->tab[display->i]);
		else if (first)
			ft_printf("\n%s", display->tab[display->i]);
		else
		{
			ft_printf("%s", display->tab[display->i]);
			display->check_first = 1;
		}
	}
	else
		ft_printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*show8(t_option *option, t_display *display, int r)
{
	if (option->optionl)
	{
		set_display_time(option, display);
		show7(option, display, display->check_first2);
	}
	if (option->optiona)
		show3(option, display, display->check_first2);
	if (r && !(option->optiona))
		show5(option, display, display->check_first);
	else if (display->tab[display->i][0] != '.' && !(option->optiona) && !(r))
		show4(option, display, display->check_first);
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
			show8(option, display, r);
			if (option->optionr)
				if (display->i == 0)
					break ;
			counter(display, option);
			if (display->check_first)
				first = display->check_first;
			if (display->check_first2)
				first2 = display->check_first2;
		}
	}
	if (r && !(option->optionl))
		ft_printf("\n");
}
