/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:08:37 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/11 10:16:05 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*r;
	int		l;

	l = ft_strlen(src);
	r = malloc(l + 1);
	l = 0;
	if (r == NULL)
		return (NULL);
	while (src[l])
	{
		r[l] = src[l];
		l++;
	}
	r[l] = '\0';
	return (r);
}
