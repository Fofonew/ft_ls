/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:46:57 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:46:59 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
		ft_putchar_fd('-', fd);
	n2 = (n < 0 ? -n : n);
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putchar_fd(n2 % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n2 + '0', fd);
}
