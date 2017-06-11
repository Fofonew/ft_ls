/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <doriol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:54:08 by doriol            #+#    #+#             */
/*   Updated: 2017/04/12 19:44:44 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	f;
	char			*bigcp;
	char			*littlecp;

	bigcp = (void *)big;
	littlecp = (void *)little;
	i = 0;
	j = 0;
	f = 0;
	if (littlecp[0] == '\0')
		return (bigcp);
	while (bigcp[i])
	{
		j = i;
		while (bigcp[j++] == littlecp[f++])
		{
			if (littlecp[f] == '\0')
				return (&bigcp[i]);
		}
		f = 0;
		i++;
	}
	return (NULL);
}
