/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:48:36 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:48:39 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_add_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	word = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	tab = (char**)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tab[i++] = ft_add_word(s, c);
			while (*s && *s != c)
				s++;
		}
		else
			while (*s && *s == c)
				s++;
	}
	return (tab);
}
