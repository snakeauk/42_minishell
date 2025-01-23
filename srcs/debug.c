#include "debug.h"

void	debug_parser(t_ast **ast)
{
	if (!ast || !*ast)
		return ;
	if ((*ast)->left)
	{
		debug_parser(&(*ast)->right);
	}
	else if ((*ast)->right)
	{
		debug_parser(&(*ast)->right);
	}
	if ((*ast)->token)
		debug_token(&(*ast)->token);
}

int	debug_token(t_token **token)
{
	int			ret;
	static char	*token_type[] = {"WORD", "PIPE", "REDIRECT_IN", "REDIRECT_OUT",
			"REDIRECT_APPEND", "HEREDOC", "SQUOTE", "DQUOTE", "SENTINEL",
			"ERROR"};

	LOG;
	if (!token)
		return (0);
	ret = 0;
	while (*token)
	{
		printf("%d:%s:%s\n", ret + 1, token_type[(*token)->type], (*token)->string);
		*token = (*token)->next;
		ret++;
	}
	LOGOUT;
	return (ret);
}