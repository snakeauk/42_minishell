# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_builtins.h"

int main(int argc, char **argv);
int ft_readline(char *message);

# endif