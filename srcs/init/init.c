#include "init.h"

void	list_append(char *key_pair, t_list **list)
{
	t_list	*new_node;
	t_list	*cur;

	new_node = ft_lstnew(ft_strdup(key_pair));
	if (!new_node)
	{
		perror("list_append");
		return ;
	}
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
}

static t_list	*envp_to_list(char **envp)
{
	t_list	*env;
	char	*home;

	env = NULL;
	if (!envp)
		return (NULL);
	while (*envp)
	{
		list_append(*envp, &env);
		envp++;
	}
	if (!minienv_node("OLDPWD", env))
		list_append("OLDPWD", &env);
	home = ft_strjoin("__HOME=", minienv_value("HOME", env));
	list_append(home, &env);
	free(home);
	return (env);
}

t_minishell	*init_minishell(char **envp)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!minishell)
	{
		perror("init_minishell");
		return (NULL);
	}
	minishell->env = envp_to_list(envp);
	return (minishell);
}
