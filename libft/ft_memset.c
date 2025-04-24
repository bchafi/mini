/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:03:13 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/22 15:32:10 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_res;

	mem_res = (unsigned char *)s;
	while (n > 0)
	{
		*mem_res++ = (unsigned char)c;
		n--;
	}
	return (s);
}
