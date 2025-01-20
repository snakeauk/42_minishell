#include "minishell.h"

void	free_token(t_token **token)
{
}

void free_minishell(t_minishell *minishell)
{
	if (minishell->token)
		free_token(minishell->token);
}
