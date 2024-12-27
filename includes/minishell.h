# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_builtins.h"

enum type {
    COMMAND,
    PIPE,
    DQUOTATION,
    SQUOTATION,
};

typedef struct s_cmd
{
    enum type       type;
    struct s_cmd    *right;
    struct s_cmd    *left;
}           t_cmd;


int main(int argc, char **argv);
int ft_readline(char *message);

# endif