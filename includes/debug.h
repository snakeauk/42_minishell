#ifndef DEBUG_H
# define DEBUG_H

#include "struct.h"
#include <stdio.h>

int	debug_lexer(t_token **token);
void	debug_parser(t_ast **ast);

#endif