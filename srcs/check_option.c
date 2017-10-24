/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:24 by doriol            #+#    #+#             */
/*   Updated: 2017/10/24 16:54:04 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_option	*check_option2(char **v, t_option *option, int x)
{
	int y;

	y = 1;
	while (v[x][y])
	{
		if (v[x][y] == 'R')
			option->optionrr = 1;
		if (v[x][y] == 'r')
			option->optionr = 1;
		if (v[x][y] == 'a')
			option->optiona = 1;
		if (v[x][y] == 'l')
			option->optionl = 1;
		if (v[x][y] == 't')
			option->optiont = 1;
		if (v[x][y] != 'R' && v[x][y] != 'r' && v[x][y] != 'a' &&
				v[x][y] != 'l' && v[x][y] != 't')
		{
			printf("ft_ls: illegal option -- %c\nusage: ft_ls \
					[-arRlt] [file ...]\n", v[x][y]);
			exit(1);
		}
		y++;
	}
	return (option);
}

int			check_option3(char **v, t_option *option, int x, int e)
{
	static	int	secondpass;

	secondpass = 0;
	if (option->optionrr == 1)
		recursive_check(v[x], option);
	else
	{
		if (e)
			printf("\n");
		e = 1;
		if (v[x][0] != '.')
			printf("%s:\n", v[x]);
		show_content(v[x], 0, option);
	}
	secondpass = 1;
	return (e);
}

t_option	*check_option(char **v, t_option *option)
{
	int			x;
	int			secondpass;
	static int	e;
	int			y;

	x = 1;
	secondpass = 0;
	e = 0;
	while (v[x])
	{
		y = 1;
		if (v[x][0] == '-')
			check_option2(v, option, x);
		else
			check_option3(v, option, x, e);
		x++;
	}
	if (v[x - 1][0] == '-' && option->optionrr != 1)
		show_content(".", 0, option);
	else if (v[x - 1][0] == '-' && option->optionrr == 1)
		recursive_check(".", option);
	else if (secondpass != 1)
		show_content(v[x - 1], 0, option);
	return (option);
}
