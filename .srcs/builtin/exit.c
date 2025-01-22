#include "ft_builtins.h"

int builtin_exit(int argc, char **argv)
{
    int status;

    if (argc == 1)
        exit(0);
    if (argc != 2)
        ft_dprintf(STDERR_FILENO, "cd: too many arguments\n");
    else
    {
        if (!ft_isdigit(argv[1][0]))
        {
            ft_dprintf(STDERR_FILENO, \
                "exit: %s: numeric argument required\n", argv[1]);
            status = 2;
        }
        else
            status = ft_atoi(argv[1]);
        exit(status % 256);
    }
    return (0);
}
