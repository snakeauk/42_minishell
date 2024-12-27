# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include "ft_builtins.h"

enum type {
    COMMAND,
    PIPE,
    DQUOTATION,
    SQUOTATION,
};

typedef struct s_flags
{
    int PIPE;
    int DQUOTATION;
    int SQUOTSTION;
    int 
}               t_lexer;

typedef struct s_word_desc
{
    char    *word; /* Zero terminated string. */
    int     flags; /* Flags associated with this word. */
}               t_word_desc;

typedef struct s_word_list
{
    struct s_word_list  *next;
    t_word_desc         *word;
}               t_word_list;


# endif