/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:25:08 by achnouri          #+#    #+#             */
/*   Updated: 2025/04/17 20:05:14 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int create_children(test_data *data)
{
    
}

static int initialize_for_execution(test_data *data)
{
       
}

int execute(test_data *data)
{
    int r;

    r = initialize_for_execution(data);
    if(r != CMD_NOT_FOUND)
        return(r);


    return(create_children(data));
}