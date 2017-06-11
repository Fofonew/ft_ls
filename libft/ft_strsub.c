/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <doriol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 02:18:52 by doriol            #+#    #+#             */
/*   Updated: 2017/04/13 05:20:43 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(cp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cp[len] = '\0';
	while (len--)
	{
		cp[i] = s[start];
		i++;
		start++;
	}
	return (cp);
}
