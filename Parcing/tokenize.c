/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:35:11 by bchafi            #+#    #+#             */
/*   Updated: 2025/04/23 22:45:07 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *new_token(char *value, t_token_type type, t_garbage *gc_garbge)
{
    t_token *tok = gc_malloc(sizeof(t_token), &gc_garbge);
    if (!tok)
        return (NULL);
    tok->value = value;
    tok->type = type;
    tok->next = NULL;
    tok->prev = NULL;
    return (tok);
}

void add_token(t_token **tokens, t_token *new)
{
    if (!*tokens)
        *tokens = new;
    else
    {
        t_token *tmp = *tokens;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}
void handle_operator(const char *input, int *i, t_token **tokens, t_garbage *gc)
{
    if (input[*i] == '>' && input[*i + 1] == '>')
    {
        add_token(tokens, new_token(ft_strdup(">>"), APPEND_OUT, gc));
        (*i) += 2;
    }
    else if (input[*i] == '<' && input[*i + 1] == '<')
    {
        add_token(tokens, new_token(ft_strdup("<<"), HEREDOC, gc));
        (*i) += 2;
    }
    else if (input[*i] == '|' && input[*i + 1] == '|')
    {
        add_token(tokens, new_token(ft_strdup("||"), OR_IF, gc));
        (*i) += 2;
    }
    else if (input[*i] == '&' && input[*i + 1] == '&')
    {
        add_token(tokens, new_token(ft_strdup("&&"), AND_IF, gc));
        (*i) += 2;
    }
    else if (input[*i] == '|')
    {
        add_token(tokens, new_token(ft_strdup("|"), PIPE, gc));
        (*i)++;
    }
    else if (input[*i] == '<')
    {
        add_token(tokens, new_token(ft_strdup("<"), REDIRECT_IN, gc));
        (*i)++;
    }
    else if (input[*i] == '>')
    {
        add_token(tokens, new_token(ft_strdup(">"), REDIRECT_OUT, gc));
        (*i)++;
    }
}

t_token *tokenize(const char *input, t_garbage *gc_garbge)
{
    int i = 0;
    int start = 0;
    t_token *tokens = NULL;
    int check_paren = 0;

    while (input[i])
    {
        // Skip spaces and tabs
        if (input[i] == ' ' || input[i] == '\t')
            i++;
        // Handle "operators"
        else if ((input[i] == '>' || input[i] == '<' || input[i] == '|' || input[i] == '&') && input[i + 1])
            handle_operator(input, &i, &tokens, gc_garbge);
        // Handle double quotes (with expansion)
        else if (input[i] == '"')
        {
            i++;
            start = i;
            while (input[i] && input[i] != '"')
            {
                if (input[i] == '$')
                {
                    if (start != i && (input[i + 1] == ' ' || input[i + 1] == '\t'))
                        add_token(&tokens, new_token(ft_strndup(&input[start], i - start), DOUBLE_QUOTE, gc_garbge));
                    i++;
                    start = i;
                    if (input[i] == '?')
                    {
                        add_token(&tokens, new_token(ft_strdup("?"), VARIABLE, gc_garbge));
                        i++;
                    }
                    else
                    {
                        --i;
                        while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
                            i++;
                        if (start != i)
                            add_token(&tokens, new_token(ft_strndup(&input[start], i - start), VARIABLE, gc_garbge));
                    }
                    start = i;
                }
                else
                    i++;
            }
            if (input[i] != '"')
                check_error("Minishell: syntax error unclosed Double Quote!", tokens);
            if (start != i)
                add_token(&tokens, new_token(ft_strndup(&input[start], i - start), DOUBLE_QUOTE, gc_garbge));
            i++;
        }
        else if (input[i] == '\'')
        {
            i++;
            start = i;
            while (input[i] && input[i] != '\'')
                i++;
            if (input[i] != '\'')
                check_error("Minishell: syntax error unclosed Single Quote!", tokens);
            add_token(&tokens, new_token(ft_strndup(&input[start], i - start), SINGLE_QUOTE, gc_garbge));
            i++;
        }
        // Handle parentheses
        else if (input[i] == '(')
        {
            add_token(&tokens, new_token(ft_strdup("("), LEFT_PAREN, gc_garbge));
            check_paren += 1;
            i++;
        }
        else if (input[i] == ')')
        {
            add_token(&tokens, new_token(ft_strdup(")"), RIGHT_PAREN, gc_garbge));
            check_paren += 1;
            i++;
        }
        // Handle variables
        else if (input[i] == '$')
        {
            i++;
            start = i;
            while (input[i] && input[i] != ' ')
                i++;
            add_token(&tokens, new_token(ft_strndup(&input[start], i - start), VARIABLE, gc_garbge));
            i++;
        }
        // Handle regular words
        else
        {
            start = i;
            while (input[i] && input[i] != ' ' && input[i] != ';' && input[i] != '&' && input[i] != '(' && input[i] != ')' && input[i] != '\t' && input[i] != '|' && input[i] != '<' && input[i] != '>' && input[i] != '$')
                i++;
            if (input[i] == ';')
                check_error("Minishell: syntax error unexpected token `;'", tokens);
            add_token(&tokens, new_token(ft_strndup(&input[start], i - start), WORD, gc_garbge));
        }
    }
    if (check_paren % 2 != 0)
        check_error("Minishell: syntax error unclosed Paren", tokens);
    return (tokens);
}

// t_tree *create_node(t_token_type type)
// {
//     t_tree *new_root = malloc(sizeof(t_tree));
//     if (!new_root)
//         return NULL;
//     new_root->type = type;
//     new_root->left = NULL;
//     new_root->right = NULL;
//     new_root->cmd = NULL;
//     new_root->redir_file = NULL;
//     new_root->redir_type = 0;
//     return new_root;
// }

// t_tree *parse_expression(t_token *tokens, t_token *end)
// {
//     t_tree *tree;
//     t_token *current = tokens;
//     tree = NULL;
//     while (current && current != end)
//     {
//         if (current->type == AND_IF || current->type == OR_IF)
//         {
//             tree = create_node(current->type);
//             tree->left = parse_expression(tokens, current);
//             tree->right = parse_expression(current->next, NULL);
//             return tree;
//         }
//         current = current->next;
//     }
//     return tree;
// }

t_tree *tree_input(const char *input)
{
    t_tree *tree = NULL;
    t_garbage *garbage = NULL;
    t_token *tok = tokenize(input, garbage);
    // if (tok)
    //     syntax_error(tok);
    t_token *tmp = tok;
    while (tmp)
    {
        printf("%s => %s\n", tmp->value, get_token_type_desc(tmp->type));
        tmp = tmp->next;
    }
    // tok = syntax_error(tok);
    // tree = parse_expression(tok);
    return (tree);
}
