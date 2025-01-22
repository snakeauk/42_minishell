#include "minishell.h"

t_minishell	*init_minishell(char **envp)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!minishell)
	{
		perror("init_minishell");
		return (NULL);
	}
	// minishell->envp = envp;
	return (minishell);
}

void	init_line(t_minishell *minishell)
{
	free(minishell->line);
	minishell->line = NULL;
	free_token(&minishell->token);
	minishell->token = NULL;
	free_ast(&minishell->ast);
	minishell->ast = NULL;
}