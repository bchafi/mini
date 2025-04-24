
#include "../minishell.h"

void *gc_malloc(size_t size, t_garbage **garbage)
{
    void *ptr = malloc(size);
    t_garbage *new_node;

    if (!ptr)
        return NULL;
    new_node = malloc(sizeof(t_garbage));
    if (!new_node)
        return NULL;
    new_node->ptr = ptr;
    new_node->next = *garbage;
    *garbage = new_node;
    return ptr;
}

void free_tokens(t_token *tokens)
{
    if (!tokens)
        return;
    t_token *tmp;
    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
}
void check_error(char *str, t_token *tokens)
{
    if (str)
        printf("%s\n", str);
    if (tokens)
        free_tokens(tokens);
}

