#include "debug.h"

void	debug_parser(t_ast *ast)
{
	LOG;
	if (!ast)
		return ;
	if (ast->left)
	{
		puts("<--");
		debug_parser(ast->left);
	}
	if (ast->right)
	{
		puts("-->");
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

// void debug_print_ast(t_ast *ast, int level)
// {
// 	t_token *current;

// 	LOG;
//     if (!ast)
//         return;
//     for (int i = 0; i < level; i++)
//         printf("\t");
//     if (ast->token)
// 		debug_token(&ast->token);
//     if (ast->redirect)
// 		debug_token(&ast->redirect);
//     debug_print_ast(ast->left, level + 1);
//     debug_print_ast(ast->right, level + 1);
// 	LOGOUT;
// }
