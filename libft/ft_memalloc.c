/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <doriol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:18:05 by doriol            #+#    #+#             */
/*   Updated: 2017/04/12 23:54:57 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memalloc;

	if (!(memalloc = (void *)malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_bzero(memalloc, size);
	return (memalloc);
}
