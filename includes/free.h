#ifndef FREE_H
# define FREE_H

#include <stdlib.h>
#include "struct.h"
#include "libft.h"

void	free_ast(t_ast **ast);
void	free_token(t_token **token);
void 	free_minishell(t_minishell **minishell);

#endif