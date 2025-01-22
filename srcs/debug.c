#include "debug.h"

int	debug_token(t_token *token)
{
	int	ret;

	LOG;
	ret = 0;
	while (token)
	{
		printf("----------------------\n");
		printf("%s\n", token->string);
		ret++;
		token = token->next;
	}
	return (ret);
}

void	print_ast(t_ast *ast)
{
	LOG;
	if (!ast)
		return ;
	if (ast->left)
	{
		print_ast(ast->left);
	}
	if (ast->right)
	{
		print_ast(ast->right);
	}
	if (ast->token)
		debug_token(ast->token);
}

int	print_token(t_token *token)
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
		printf("%d:\t%s:\t%s\n", ret + 1, token_type[token->type],
			token->string);
		token = token->next;
		ret++;
	}
	LOGOUT;
	return (ret);
}
