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
    // envデバック用
    // debug_env(minishell->env);
    rl_clear_history();
    while (1)
    {
        input = readline("minishell$ ");
        if (!*input)
            continue ;
        add_history(input);
        // ============lexer===============
        minishell->token = lexer(input);
        free(input);
        if (!minishell->token)
            continue;
        // lexerデバック用
        // debug_token(&minishell->token);

        // ============parser===============
        minishell->ast = parser(minishell->token);
        free_token(&minishell->token);
        if (!minishell->ast)
            continue;
        // // parserデバック用
        debug_parser(minishell->ast);

        // ============expansion===============


        // ============execution===============
        // ret = builtin_switch(ft_arraylen((void **)cmd), cmd);
        // ft_free_array2((void **)cmd);
        free_token(&minishell->token);
        free_ast(&minishell->ast);
    }
    return (ret);
}
