
#include "../minishell.h"

char *get_token_type_desc(int type)
{
    if (type == 0)
        return "WORD";
    else if (type == 1)
        return "SINGLE_QUOTE";
    else if (type == 2)
        return "DOUBLE_QUOTE";
    else if (type == 3)
        return "REDIRECT_IN";
    else if (type == 4)
        return "REDIRECT_OUT";
    else if (type == 5)
        return "APPEND_OUT";
    else if (type == 6)
        return "HEREDOC";
    else if (type == 7)
        return "PIPE";
    else if (type == 8)
        return "AND_IF";
    else if (type == 9)
        return "OR_IF";
    else if (type == 10)
        return "LEFT_PAREN";
    else if (type == 11)
        return "RIGHT_PAREN";
    else if (type == 12)
        return "VARIABLE";
    else
        return "UNKNOWN";
}

