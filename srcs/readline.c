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

int ft_readline(t_minishell *minishell)
{
    char    *input;
    char    **cmd;
    int     ret;

    ret = 0;
    rl_clear_history();
    while (1)
    {
        input = readline("minishell$ ");
        if (!*input)
            continue ;
        add_history(input);
        minishell->token = lexer(input);
        free(input);
        if (!minishell->token)
            continue;

        // lexerデバック用
        // debug_token(&minishell->token);

        minishell->ast = parser(minishell->token);
        if (!minishell->ast)
            continue;
        // // parserデバック用
        free_token(&minishell->token);
        debug_parser(minishell->ast);
        // debug_print_ast(minishell->ast, 0);

        // ret = builtin_switch(ft_arraylen((void **)cmd), cmd);
        // ft_free_array2((void **)cmd);
        // free_token(&minishell->token);
        free_ast(&minishell->ast);
    }
    return (ret);
}
