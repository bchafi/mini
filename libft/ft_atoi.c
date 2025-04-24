/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:56 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/13 12:50:53 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	t;
	long	b;

	b = 0;
	t = 0;
	s = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			s *= -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		b = t;
		t = ((t * 10) + (str[i] - 48));
		if (b != (t / 10) && s == -1)
			return (0);
		if (b != (t / 10) && s == 1)
			return (-1);
		i++;
	}
	return ((int)t * s);
}
