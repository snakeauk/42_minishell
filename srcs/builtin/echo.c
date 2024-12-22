#include "ft_builtins.h"

int builtin_echo(int argc, char **argv)
{
    int index;

    if (argc == 1)
    {
        ft_dprintf(STDOUT_FILENO, "\n");
        return (0);
    }
    index = 1;
    while (index < argc)
    {
        if (index != 1)
            ft_dprintf(STDOUT_FILENO, " ");
        ft_dprintf(STDOUT_FILENO, "%s", argv[index]);
        if (index == argc - 1)
            ft_dprintf(STDOUT_FILENO, "\n");
        index++;
    }
    return (0);
}
