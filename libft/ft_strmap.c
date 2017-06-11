/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <doriol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 00:08:42 by doriol            #+#    #+#             */
/*   Updated: 2017/04/13 04:58:29 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*cp;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	cp = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!cp)
		return (NULL);
	cp[len] = '\0';
	while (s[i] != '\0')
	{
		cp[i] = (*f)(s[i]);
		i++;
	}
	return (cp);
}
