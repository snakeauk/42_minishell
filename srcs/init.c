#include "minishell.h"

t_minishell *init_minishell(char **envp)
{
	t_minishell *minishell;

	minishell = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!minishell)
	{
		perror("init_minishell");
		return (NULL);
	}
	minishell->envp = envp;
	return (minishell);
}
