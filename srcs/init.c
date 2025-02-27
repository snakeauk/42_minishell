#include "minishell.h"

t_list	*envp_to_list(char **envp)
{
	t_list	*env;
	t_list	*new;
	int		i;

	i = 0;
	env = NULL;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		new = ft_lstnew(ft_strdup(envp[i]));
		if (!new)
		{
			perror("envp_to_list");
			return (NULL);
		}
		ft_lstadd_back(&env, new);
		i++;
	}
	return (env);
}

t_minishell *init_minishell(char **envp)
{
	t_minishell *minishell;

	minishell = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!minishell)
	{
		perror("init_minishell");
		return (NULL);
	}
	minishell->env = envp_to_list(envp);
	return (minishell);
}
