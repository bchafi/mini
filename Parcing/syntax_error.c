
#include "../minishell.h"


t_token *syntax_error(t_token *tokens)
{
    t_token *tmp;
    if (!tokens)
    {
        check_error("Minishell: syntax error (empty input)", NULL);
        return;
    }
    tmp = tokens;
    while (tokens)
    {
        if (tokens->type == PIPE)
        {
            if (tokens->prev == NULL || tokens->next == NULL || (tokens->next 
                && (tokens->next->type == PIPE || tokens->next->type == AND_IF || tokens->next->type == OR_IF)))
            {
                check_error("Minishell: syntax error near unexpected token `|'", tokens);
                break;
            }
        }
        if (tokens->type == AND_IF || tokens->type == OR_IF)
        {
            if (tokens->prev == NULL || tokens->next == NULL || tokens->next->type == AND_IF || tokens->next->type == OR_IF || tokens->next->type == PIPE)
            {
                check_error("Minishell: syntax error near unexpected token `&&' or `||'", tokens);
                break;
            }
        }
        if (tokens->type == REDIRECT_IN || tokens->type == REDIRECT_OUT || tokens->type == APPEND_OUT || tokens->type == HEREDOC)
        {
            if (!tokens->next || tokens->next->type != WORD)
            {
                check_error("Minishell: syntax error near redirection", tokens);
                break;
            }
        }
        if (tokens->type == LEFT_PAREN && tokens->next && tokens->next->type == RIGHT_PAREN)
        {
            check_error("Minishell: syntax error near empty `()'", tokens);
            break;
        }
        tokens = tokens->next;
    }
    return (tmp);
}