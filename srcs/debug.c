#include "debug.h"

void	debug_parser(t_ast *ast)
{
	LOG;
	if (!ast)
		return ;
	if (ast->left)
	{
		debug_parser(ast->left);
	}
	if (ast->right)
	{
		debug_parser(ast->right);
	}
	debug_token(ast->token);
	debug_token(ast->redirect);
	LOGOUT;
}

int	debug_token(t_token *token)
{
	int			ret;
	static char	*token_type[] = {"WORD", "PIPE", "REDIRECT_IN", "REDIRECT_OUT",
			"REDIRECT_APPEND", "HEREDOC", "SQUOTE", "DQUOTE", "SENTINEL",
			"ERROR"};

	LOG;
	if (!token)
		return (0);
	ret = 0;
	while (token)
	{
		printf("%d:%s:%s\n", ret + 1, token_type[token->type], token->string);
		token = token->next;
		ret++;
	}
	LOGOUT;
	return (ret);
}

int	debug_env(t_list *env)
{
	t_list	*current;
	int		index;

	LOG;
	if (!env)
		return (0);
	current = env;
	index = 0;
	while (current)
	{
		printf("%d:\t%s\n", index, (char *)current->content);
		current = current->next;
		index++;
	}
	LOGOUT;
	return (index);
}
