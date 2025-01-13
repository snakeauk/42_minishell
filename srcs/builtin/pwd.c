#include "ft_builtins.h"

int builtin_pwd(int argc, char **argv)
{
    char *buf;

    buf = ft_getenv("PWD");
    if (argc == 1 || buf)
        ft_printf("%s\n", buf);
    return (0);
}
