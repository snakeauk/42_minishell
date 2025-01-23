#include "lexer.h"

t_token	*token_init_node(char *string, t_token_type type)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		perror("lexer");
		return (NULL);
	}
	token->string = string;
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*token_last(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void	token_append(t_token **tokens, t_token *node)
{
	t_token	*last;

	if (!*tokens)
		*tokens = node;
	else
	{
		last = token_last(*tokens);
		last->next = node;
	}
}
