#ifndef PARSER_H
# define PARSER_H

#include "struct.h"
#include "libft.h"
#include "ft_printf.h"
#include "free.h"
#include "type.h"
#include "lexer.h"

t_ast	*parser(t_token *token);

#endif