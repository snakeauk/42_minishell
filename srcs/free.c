#include "free.h"

void	free_token(t_token **token);
void 	free_minishell(t_minishell *minishell);

void	free_token(t_token **token)
{
	t_token *cur;
	t_token *next;

	if (!token || !*token)
		return ;
	cur = *token;
	while (cur)
	{
		next = cur->next;
		if (cur->string)
			free(cur->string);
		free(cur);
		cur = next;
	}
	*token = NULL;
}

void free_minishell(t_minishell *minishell)
{
	if (minishell->token)
		free_token(minishell->token);
}
