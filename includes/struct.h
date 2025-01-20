#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_token_type {
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    REDIRECT_APPEND,
    HEREDOC,
    SQUOTE,
    DQUOTE
	// SEMICOLON
}               t_token_type;

typedef struct s_token
{
	char			*string;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

typedef struct s_minishell
{
	char **envp;
	t_token **token;
}	t_minishell;

#endif