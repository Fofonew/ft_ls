/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fofow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:48:40 by fofow             #+#    #+#             */
/*   Updated: 2017/11/22 16:48:43 by fofow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;

	if (!*needle)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, size))
		++haystack;
	return (ft_strncmp(haystack, needle, size)) ? NULL : (char*)haystack;
}
