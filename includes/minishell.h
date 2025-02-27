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
#include "init.h"
#include "lexer.h"
#include "parser.h"
#include "ft_builtins.h"
#include "free.h"
#include "debug.h"
#include "minienv.h"

int		main(int argc, char **argv, char **envp);
int 	ft_readline(t_minishell *minishell);
char	*ft_getenv(char *path);

// is
int	is_pipe(char c);

#endif