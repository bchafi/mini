/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:20:53 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/04 18:19:01 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (s == 0)
		return (len_s);
	while (*(src + i) && i < (s - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (len_s);
}
