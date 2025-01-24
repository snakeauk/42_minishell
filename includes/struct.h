#ifndef STRUCT_H
# define STRUCT_H

#include "libft.h"

typedef enum e_token_type {
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    REDIRECT_APPEND,
    HEREDOC,
    SQUOTE,
    DQUOTE,
    ERROR
	// SEMICOLON
}               t_token_type;

typedef struct s_token
{
	char			*string;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

typedef struct s_ast
{
    t_token         *token;
    t_token         *redirect;
    struct s_ast    *left;
    struct s_ast    *right;
}               t_ast;

typedef struct s_minishell
{
	t_list  *env;
	t_token *token;
    t_ast   *ast;
}	t_minishell;

#endif