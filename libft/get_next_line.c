/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:20:43 by doriol            #+#    #+#             */
/*   Updated: 2017/05/03 14:21:30 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd		*get_maill(t_fd *first, int fd)
{
	t_fd		*maill;

	maill = first;
	while (maill && maill->fd != fd)
		maill = maill->next;
	if (!maill)
	{
		if (!(maill = malloc(sizeof(t_fd))))
			return (NULL);
		maill->s = ft_strnew(0);
		maill->fd = fd;
		maill->next = 0;
		while (first && first->next)
			first = first->next;
		if (first)
			first->next = maill;
	}
	return (maill);
}

static int		save(t_fd *maill, char **tmp, char ***line)
{
	*tmp = ft_strdup(maill->s);
	if (**tmp == '\n')
	{
		free(maill->s);
		maill->s = ft_strdup(*tmp + 1);
		free(*tmp);
		**line = ft_strnew(0);
		return (1);
	}
	free(maill->s);
	maill->s = ft_strchr(*tmp, '\n') ?
	ft_strdup(ft_strchr(*tmp, '\n') + 1) : ft_strnew(0);
	if (ft_strchr(*tmp, '\n'))
		*ft_strchr(*tmp, '\n') = '\0';
	**line = *tmp;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	ssize_t			st;
	static t_fd		*first;
	t_fd			*maill;
	char			*tmp;

	if (fd < 0)
		return (-1);
	maill = get_maill(first, fd);
	first = first ? first : maill;
	while ((st = read(fd, buf, BUFF_SIZE)))
	{
		if (st == -1)
			return (-1);
		buf[st] = '\0';
		tmp = ft_strjoin(maill->s, buf);
		free(maill->s);
		maill->s = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(maill->s, '\n'))
			break ;
	}
	if (save(maill, &tmp, &line))
		return (1);
	return (!!(*tmp));
}
