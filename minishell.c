#include "minishell.h"

void prompt(void)
{
    char *input;
    rl_catch_signals = 0;
    while (1)
    {
        input = readline("MiniShell-$ ");
        if (!input)
        {
            write(1, "\033[1A\033[2KMiniShell-$ exit", 26);
            break;
        }
        if (*input)
        {
            add_history(input);
            tree_input(input);
        }
        free(input);
    }
}


void f(void)
{
    system("leaks minishell");
}

int main(int ac, char **av)
{
    (void)av;
    // atexit(f);
    if (ac == 1)
    {
        signal(SIGINT, handle_sigint);
        signal(SIGQUIT, SIG_IGN);
        prompt();
    }
    
    return (0);
}
