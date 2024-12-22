#include "ft_builtins.h"

int ft_strcmp(const char *s1, const char *s2)
{
    return (ft_strncmp(s1, s2, ft_strlen(s1)) == 0
        && ft_strlen(s1) == ft_strlen(s2));
}

int builtin_switch(int argc, char **argv)
{
    int ret;

    if (!argv)
    {
        ft_dprintf(STDERR_FILENO, "Error: builtin_switch: argv is null\n");
        return (1);
    }
    ret = 0;
    if (ft_strcmp(argv[0], "echo"))
        ret = builtin_echo(argc, argv);
    else if (ft_strcmp(argv[0], "cd"))
        ret = builtin_cd(argc, argv);
    else if (ft_strcmp(argv[0], "pwd"))
        ret = builtin_pwd(argc, argv);
    else if (ft_strcmp(argv[0], "exit"))
        ret = builtin_exit(argc, argv);
    else
    {
        ft_dprintf(STDERR_FILENO, "Error: %s: command not builtin\n", argv[0]);
        return (1);
    }
    return (ret);
}
