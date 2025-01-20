# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "ft_printf.h"
// minishell
#include "struct.h"
#include "lexer.h"
#include "ft_builtins.h"

int main(int argc, char **argv, char **envp);
int ft_readline(void);
char    *ft_getenv(char *path);

#endif