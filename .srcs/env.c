#include "minishell.h"

char    *ft_getenv(char *path)
{
    char    *env;

    env = getenv(path);
    if (env == NULL)
    {
        ft_dprintf(STDERR_FILENO, "Error: %s: path not find", path);
        return (NULL);
    }
    return (env);
}
