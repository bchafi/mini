/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:50:08 by bchafi            #+#    #+#             */
/*   Updated: 2025/04/23 19:07:24 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


// #define RL_READLINE_VERSION 0x0600
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef enum token_type
{
    WORD,
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    REDIRECT_IN,
    REDIRECT_OUT,
    APPEND_OUT,
    HEREDOC,
    PIPE,
    AND_IF,
    OR_IF,
    LEFT_PAREN,
    RIGHT_PAREN,
    VARIABLE,
    GROUP,
    CMD,
    REDIR,
} t_token_type;

typedef struct s_garbage
{
    void *ptr;
    struct s_garbage *next;
} t_garbage;

// the token of the keyword
typedef struct s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
    struct s_token  *prev;
}   t_token;

typedef struct s_tree
{
    t_token_type type;
    char        **cmd;       // only for CMD nodes: the full command split by space
    int         redir_type;  // for redirections: > >> < <<
    char        *redir_file; // file name if it's a redirection
    struct s_tree *left;
    struct s_tree *right;
}   t_tree;

void    *gc_malloc(size_t size, t_garbage **garbage);
void    free_tokens(t_token *tokens);
void    check_error(char *str, t_token *tokens);
void    check_error(char *str, t_token *tokens);
char    *get_token_type_desc(int type);
void    handle_sigint(int sig);
t_token *syntax_error(t_token *tokens);
t_token *new_token(char *value, t_token_type type, t_garbage *gc_garbge);
void    add_token(t_token **tokens, t_token *new);
t_token *tokenize(const char *input, t_garbage *gc);
t_tree  *tree_input(const char *input);




// execution
// temporary lists for testing

typedef struct a_list
{
    char **args;
    char *cmd;
    char *path;
} test_command;

typedef struct b_list
{
    char *user_entry;
    char **env;
    char *current_dir;
    char *previous_dir;
    pid_t   pid;
    test_command *command;
} test_data;

// temoprary prototypes for testing
int execute_prompt_test_for_builtins(char *prompt);
// builtins functions
int echo_builtin(/**/);
int cd_builtin(/**/);
int pwd_builtin(/**/);
int exit_builtin(/**/);
int export_builtin(/**/);
int unset_builtin(/**/);
int env_builtin(/**/);


// static int initialize_for_execution(test_data *data);



// flags
#define CMD_NOT_FOUND 404
#define SUCCESS_EXIT 200
#define FAILURE_EXIT 400
#define SUCCESS 1
#define FAILURE 0





//********************************************************
#endif