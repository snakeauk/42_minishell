# ifndef BUILTINS_H
# define BUILTINS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h" // cmp.c

// for pwd.c

int builtin_switch(int argc, char **argv, t_list *minienv);
int builtin_echo(int argc, char **argv);
int builtin_cd(int argc, char **argv, t_list *minienv);
int builtin_pwd(int argc, char **argv);
int builtin_exit(int argc, char **argv);

# endif