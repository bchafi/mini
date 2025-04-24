/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:54:19 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/04 18:30:57 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(haystack + i + j) && *(needle + j) \
				&& i + j < len && *(haystack + i + j) == *(needle + j))
			j++;
		if (!*(needle + j))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
