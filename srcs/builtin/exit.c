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
        status = ft_atoi(argv[1]);
        exit(status % 256);
    }
    return (0);
}
