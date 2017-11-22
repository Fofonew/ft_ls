/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:45:19 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:45:24 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa(int n)
{
	char			*nbr;
	int				neg;
	unsigned int	nb2;
	int				count;

	neg = (n < 0 ? 1 : 0);
	nb2 = (n < 0 ? -n : n);
	count = 1;
	while (nb2 >= 10)
	{
		nb2 /= 10;
		count++;
	}
	nbr = (char*)malloc(sizeof(char) * (count + neg + 1));
	if (!nbr)
		return (NULL);
	nbr[count + neg] = '\0';
	nb2 = (n < 0 ? -n : n);
	while (count-- > 0)
	{
		nbr[count + neg] = nb2 % 10 + '0';
		nb2 /= 10;
	}
	nbr[0] = (neg ? '-' : nbr[0]);
	return (nbr);
}
