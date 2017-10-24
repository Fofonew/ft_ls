/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:46:16 by doriol            #+#    #+#             */
/*   Updated: 2017/10/24 21:35:33 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"



t_display			*show_content5(t_display *display, char *dir_name, t_option *option)
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
		{
			display->time[display->t2] = display->tmp[display->t];
			display->t2++;
			display->t++;
		}
	}
	return (display);
}

t_display			*show_content4(t_display *display, char *dir_name, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display			*show_content3(t_display *display, char *dir_name, t_option *option)
{
	if (display->tab[display->i][0] != '.')
	{
		if (option->optionrr)
		{
			if (display->first)
				printf("\n%s", display->tab[display->i]);
			else
			{
				printf("%s", display->tab[display->i]);
				display->first = 1;
			}
		}
		else
			printf("%s\n", display->tab[display->i]);
	}
	return (display);
}

t_display			*show_content2(t_display *display, char *dir_name, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

void				show_content(char *dir_name, int r, t_option *option)
{
	t_display		*display;

	display = malloc(sizeof(t_display));
	display->i = 0;
	display->tab = parsing(dir_name, option->optiont);
	if (display->tab != NULL)
	{
		if (option->optionr)
		{
			while (display->tab[display->i])
				display->i++;
			display->i -= 1;
		}
		if (option->optionl)
		{
			lstat(display->tab[display->i], &display->bufc);
			printf("total %lld\n", display->bufc.st_blocks);
		}
		while (display->tab[display->i])
		{
			if (option->optionl)
			{
				display->t = 0;
				display->t2 = 0;
				display->stop = 0;
				lstat(display->tab[display->i], &display->buf);
				display->tmp = ctime(&display->buf.st_ctime);
				display->time = ft_strnew(12);
				show_content5(display, dir_name, option);
				if (option->optiona)
					printf("%u\t%lld\t%s ", display->buf.st_nlink, display->buf.st_size, display->time);
				else
				{
					if (display->tab[display->i][0] != '.')
						printf("%u\t%lld\t%s ", display->buf.st_nlink, \
							display->buf.st_size, display->time);
				}
			}
			if (option->optiona)
				show_content2(display, dir_name, option);
			else if (r)
				show_content3(display, dir_name, option);
			else if (display->tab[display->i][0] != '.')
				show_content4(display, dir_name, option);
			if (option->optionr)
				if (display->i == 0)
					break ;
			if (option->optionr)
				display->i--;
			else
				display->i++;
		}
	}
	if (r == 1)
		printf("\n");
}

/*t_display	*show_content_master(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionl)
		show_content5(dir_name, r, display, option);
	if (option->optiona)
		show_content4(dir_name, r, display, option);
	else if (r)
		show_content3(dir_name, r, display, option);
	else if (display->tab[display->i][0] != '.')
		show_content2(dir_name, r, display, option);
	if (option->optionr)
		if (display->i == 0)
		{
			display->breakk = 1;
			return (display);
		}
	if (option->optionr)
		display->i--;
	else
		display->i++;
	return (display);
}

t_display	*show_content6(char *dir_name, int r, t_display *display, t_option *option)
{
	if (display->tmp[display->t] == ':')
	{
		display->stop++;
		if (display->stop == 2)
		{
			display->breakk = 1;
			return (display);
		}
	}
	if (display->t < 4)
		display->t++;
	else
	{
		display->time[display->t2] = display->tmp[display->t];
		display->t2++;
		display->t++;
	}
	return (display);
}

t_display	*show_content5(char *dir_name, int r, t_display *display, t_option *option)
{
	display->t = 0;
	display->t2 = 0;
	display->stop = 0;
	lstat(display->tab[display->i], &display->buf);
	display->tmp = ctime(&display->buf.st_ctime);
	display->time = ft_strnew(12);
	while (display->tmp[display->t])
	{
		show_content6(dir_name, r, display, option);
		if (display->breakk == 1)
			break ;
	}
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

t_display	*show_content4(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*show_content3(char *dir_name, int r, t_display *display, t_option *option)
{
	if (display->tab[display->i][0] != '.')
	{
		if (option->optionrr)
		{
			if (display->first)
				printf("\n%s", display->tab[display->i]);
			else
			{
				printf("%s", display->tab[display->i]);
				display->first = 1;
			}
		}
		else
			printf("%s\n", display->tab[display->i]);
	}
	return (display);
}

t_display	*show_content2(char *dir_name, int r, t_display *display, t_option *option)
{
	if (option->optionrr)
	{
		if (display->first)
			printf("\n%s", display->tab[display->i]);
		else
		{
			printf("%s", display->tab[display->i]);
			display->first = 1;
		}
	}
	else
		printf("%s\n", display->tab[display->i]);
	return (display);
}

t_display	*set_display(t_display *display, char *dir_name, t_option *option)
{
	display->i = 0;
	display->tab = parsing(dir_name, option->optiont);
	display->breakk = 0;
	return (display);
}

void		show_content(char *dir_name, int r, t_option *option)
{
	t_display			*display;

	display = malloc(sizeof(t_display));
	set_display(display, dir_name, option);
	if (display->tab != NULL)
	{
		if (option->optionr)
		{
			while (display->tab[display->i])
				display->i++;
			display->i -= 1;
		}
		if (option->optionl)
		{
			lstat(display->tab[display->i], &display->bufc);
			printf("total %lld\n", display->bufc.st_blocks);
		}
		while (display->tab[display->i])
		{
			show_content_master(dir_name, r, display, option);
			if (display->breakk == 1)
				break ;
		}
	}
	if (r == 1)
		printf("\n");
}*/