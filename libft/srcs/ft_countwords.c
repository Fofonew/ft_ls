/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:43:50 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:43:53 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(char const *s, char c)
{
	int count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c && word)
			word = 0;
		s++;
	}
	return (count);
}
