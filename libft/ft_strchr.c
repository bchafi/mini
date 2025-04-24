/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:44:40 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/04 18:35:34 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ltr;

	ltr = (char)c;
	while (*s)
	{
		if (*s == ltr)
			return ((char *)s);
		s++;
	}
	if (ltr == '\0')
		return ((char *)s);
	return (NULL);
}
