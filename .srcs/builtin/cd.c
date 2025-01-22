#include "ft_builtins.h"

int builtin_cd(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    else if (argc != 2)
    {
        ft_dprintf(STDERR_FILENO, "cd: too many arguments\n");
        return (1);
    }
    if (chdir(argv[1]) < 0)
    {
        perror(argv[1]);
        return (1);
    }
    return (0);
}
