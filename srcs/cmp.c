#include "minishell.h"

int cmp(const char *s1, const char *s2)
{
    return (ft_strcmp(s1, s2) == 0 && ft_strlen(s1) == ft_strlen(s2));
}
