#include "free.h"

void	free_ast(t_ast **ast);
void	free_token(t_token **token);

void	free_ast(t_ast **ast)
{
	if (!ast || !*ast)
		return ;
	if ((*ast)->right)
	{
		free_ast(&(*ast)->right);
	}
	else if ((*ast)->left)
	{
		free_ast(&(*ast)->left);
	}
	if ((*ast)->redirect)
		free_token(&(*ast)->redirect);
	if ((*ast)->token)
		free_token(&(*ast)->token);
	free(*ast);
	*ast = NULL;
}

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

void free_minishell(t_minishell **minishell)
{
	if (!minishell || !*minishell)
		return ;
	if ((*minishell)->env)
		ft_lstclear(&((*minishell)->env), free);
	if ((*minishell)->token)
		free_token(&(*minishell)->token);
	if ((*minishell))
		free((*minishell));
}
