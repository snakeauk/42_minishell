#include "ft_builtins.h"

int print_echo(char *str, int e)
{
    char tmp[3];

    tmp[2] = '\0';
    while (str)
    {
        if (e && (*str == '\\' && *str + 1))
        {
            write(1, "OK!\n", 4);
            tmp[0] = *str;
            str++;
            tmp[1] = *str;
            str++;
            write(STDOUT_FILENO, tmp, 1);
        }
        else
            ft_fputc(*str, STDOUT_FILENO);
        str++;
    }
    return (0);
}

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
        print_echo(argv[index], (ft_strcmp(argv[0] , "-e")));
        ft_dprintf(STDOUT_FILENO, "\n");
        index++;
    }
    return (0);
}
