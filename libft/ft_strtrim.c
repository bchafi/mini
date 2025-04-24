/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:39:18 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/05 22:04:57 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_c(char const *spt, char c)
{
	int	i;

	i = 0;
	while (spt[i])
	{
		if (spt[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && skip_c(set, s1[i]) == 1)
		i++;
	l = ft_strlen(s1);
	while (i < l && skip_c(set, s1[l - 1]) == 1)
		l--;
	if (l <= 0)
		return (ft_strdup(""));
	p = (char *)malloc((l - i) + 1);
	if (!p)
		return (NULL);
	while (i < l)
		p[j++] = s1[i++];
	p[j] = '\0';
	return (p);
}
