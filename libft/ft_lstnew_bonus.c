/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:32:27 by achnouri          #+#    #+#             */
/*   Updated: 2024/11/11 09:50:22 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n1;

	n1 = (t_list *)malloc(sizeof(t_list));
	if (!n1)
		return (NULL);
	n1->content = content;
	n1->next = NULL;
	return (n1);
}
