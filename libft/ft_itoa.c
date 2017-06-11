/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 10:53:42 by doriol            #+#    #+#             */
/*   Updated: 2017/04/15 10:56:34 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*s;
	short			sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n < 0 ? -1 : 0;
	size = ft_digitlen(&n);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = 0;
	while (size--)
	{
		s[size] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		*s = '-';
	return (s);
}
