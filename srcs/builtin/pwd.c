#include "ft_builtins.h"

int builtin_pwd(int argc, char **argv)
{
    char *buf;

    buf = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
    if (!buf)
    {
        perror("Error: builtin_pwd");
        return (1);
    }
    if (argc == 1)
    {
        
        ft_printf("%s\n", buf);
    }
    free(buf);
    return (0);
}
