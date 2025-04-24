/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:01:44 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/17 09:40:31 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (size && count && (count * size) / size != count)
		return (NULL);
	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}
