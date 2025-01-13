# ifndef LEXER_H
# define LEXER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include "ft_builtins.h"


typedef enum e_token_type {
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    REDIRECT_APPEND,
    HEREDOC,
    VARIABLE,
    SQUOTE,
    DQUOTE,
    OTHER
}               t_token_type;

typedef struct s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
}               t_token;

t_token *lexer(const char *input);
t_token *free_token(t_token **token);
t_token *create_token(const char *value, t_token_type type);

// typedef struct s_flags
// {
//     int PIPE;
//     int DQUOTATION;
//     int SQUOTSTION;
//     int WHITESPACE;
// }               t_lexer;
// typedef struct s_word_desc
// {
//     char    *word; /* Zero terminated string. */
//     int     flags; /* Flags associated with this word. */
// }               t_word_desc;
// typedef struct s_word_list
// {
//     struct s_word_list  *next;
//     t_word_desc         *word;
// }               t_word_list;

# endif