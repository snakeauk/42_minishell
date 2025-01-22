#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_printf.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// minishell
# include "debug.h"
# include "free.h"
# include "ft_builtins.h"
# include "lexer.h"
# include "parser.h"
# include "struct.h"
/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

// int			main(int argc, char **argv, char **envp);
int			ft_readline(t_minishell *minishell);
char		*ft_getenv(char *path);

/* -----------------------------   INIT     --------------------------------- */
t_minishell	*init_minishell(char **envp);
void		init_line(t_minishell *minishell);

/* -----------------------------   SET UP   --------------------------------- */
int			is_pipe(char c);

/* -----------------------------   LEXER    --------------------------------- */
t_token		*ft_lexer(char *input);
t_token		*token_new(char *string, t_token_type type);
void		append_token(t_token **tokens, char *string, t_token_type type);
int			skip_while_next_quote(char *input, int *next_word_len);

/* -----------------------------  PARSER    --------------------------------- */
t_ast		*ft_parser(t_token *token);

#endif