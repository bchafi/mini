/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:31:29 by achnouri          #+#    #+#             */
/*   Updated: 2025/04/17 18:08:40 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_prompt_test_for_builtins(char *prompt)
{
    int r;

    r = CMD_NOT_FOUND;
    if(ft_strncmp(prompt, "echo", 5) == 0)
        r = echo_built();
    if(ft_strncmp(prompt, "cd", 3) == 0)
        r = cd_built();
    if(ft_strncmp(prompt, "pwd", 4) == 0)
        r = pwd_built();
    if(ft_strncmp(prompt, "export", 7) == 0)
        r = export_built();
    if(ft_strncmp(prompt, "unset", 6) == 0)
        r = unset_built();
    if(ft_strncmp(prompt, "env", 4) == 0)
        r = env_built();
    if(ft_strncmp(prompt, "exit", 5) == 0)
        r = exit_built();
    return(r);
}