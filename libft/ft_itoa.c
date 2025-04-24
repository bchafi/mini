/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:26:24 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/14 22:01:24 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;

	nb = n;
	len = count_numbers(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	res[len] = '\0';
	while (nb > 0)
	{
		res[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}
