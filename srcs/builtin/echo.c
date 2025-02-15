#include "ft_builtins.h"

int builtin_echo(int argc, char **argv)
{
    int i;
    int display_newline;

    i = 1;
    display_newline = 1;
    if (i < argc)
    {
        if (ft_strcmp(argv[i], "-n") == 0)
        {
            display_newline = 0;
            i++;
        }
    }
    while (i < argc)
    {
        printf("%s", argv[i]);
        i++;
        if (i < argc)
            printf(" ");
    }
    if (display_newline)
        ft_putchar('\n');
    return 0;
}
