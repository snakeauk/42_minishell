#include "minishell.h"

int ft_arraylen(void **array)
{
    int len;

    if (!array)
        return (0);
    len = 0;
    while (array[len] != NULL)
        len++;
    return (len);
}

int ft_readline(void)
{
    char    *input;
    char    **cmd;
    int     ret;
    t_token *token;

    ret = 0;
    rl_clear_history();
    while (1)
    {
        input = readline("minishell$ ");
        if (!*input)
            continue ;
        add_history(input);
        // token = lexer(input);
        // print_token(&token);
        // free_token(&token);
        // free(input);
        cmd = ft_split(input, ' ');
        free(input);
        if (!cmd || !*cmd)
            continue ;
        ret = builtin_switch(ft_arraylen((void **)cmd), cmd);
        ft_free_array2((void **)cmd);
    }
    return (ret);
}
