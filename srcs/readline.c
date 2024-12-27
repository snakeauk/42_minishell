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

char *read_line(char *message)
{
    char    *line;

    ft_fputs(message, STDOUT_FILENO);
    get_next_line(STDIN_FILENO, &line);
    line[ft_strlen(line) - 1] = '\0';
    return (line);
}

int ft_readline(char *message)
{
    char    *input;
    char    **cmd;
    int     ret;

    ret = 0;
    rl_clear_history();
    while (1)
    {
        input = readline(message);
        add_history(input);
        cmd = ft_split(input, ' ');
        free(input);
        if (!cmd)
            continue ;
        ret = builtin_switch(ft_arraylen((void **)cmd), cmd);
        ft_free_array2((void **)cmd);
    }
    rl_clear_history();
    return (ret);
}
