/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 09:53:00 by doriol            #+#    #+#             */
/*   Updated: 2017/04/15 09:53:46 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digitlen(int *n)
{
	int				size;
	long long int	ncpy;

	size = 1;
	if (*n < 0)
	{
		size += 1;
		*n *= -1;
	}
	ncpy = *n;
	while (ncpy /= 10)
		size++;
	return (size);
}
