#include "minishell.h"

char	*minienv_value(char *name, t_list *minienv)
{
	t_list	*cur;
	char	*content_str;

	cur = minienv_node(name, minienv);
	content_str = (char *)cur->content;
	if (!cur)
		return (NULL);
	return (value_only(content_str));
}

t_list	*minienv_node(char *name, t_list *minienv)
{
	t_list	*cur;
	int		size;
	char	*content_str;

	cur = minienv;
	size = ft_strlen(name);
	while (cur)
	{
		content_str = (char *)cur->content;
		if (ft_strncmp(cur->content, name, size) == 0)
			if (content_str[size] == '=')
				return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	minienv_update(char *name, char *value, t_list *minienv)
{
	t_list	*cur;
	char	*new_keypair;
	int		size;
	int		i;

	cur = minienv_node(name, minienv);
	new_keypair = create_keypair(name, value);
	if (!cur)
	{
		list_append(new_keypair, &minienv);
		free(new_keypair);
		return ;
	}
	free (cur->content);
	cur->content = new_keypair;
}
