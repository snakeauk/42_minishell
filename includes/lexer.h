# ifndef LEXER_H
# define LEXER_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "type.h"
#include "struct.h"
#include "free.h"


// lexer.c
void	lexer_meta(t_token **token, char **string);
t_token *lexer(char *input);


// lexer2.c
t_token_type	lexer_pipe(char **string);
t_token_type	lexer_redirect(char **string);

// token.c
t_token	*token_init_node(char *string, t_token_type type);
t_token	*token_last(t_token *token);
void	token_append(t_token **tokens, t_token *node);



# endif