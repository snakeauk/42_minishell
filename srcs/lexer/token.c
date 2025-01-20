#include "lexer.h"

t_token	*init_token_node(char *string, t_token_type type);
t_token	*token_last(t_token *token);
void	token_add_back(t_token **token, char *string, t_token_type type);

t_token	*init_token_node(char *string, t_token_type type)
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

void	token_add_back(t_token **token, char *string, t_token_type type)
{
	t_token *new;
	t_token *last;

	if (!string)
		return ;
	new = init_token_node(string, type);
	if (!new)
		return ;
	if (token)
	{
		if (*token)
		{
			last = token_last(*token);
			last->next = new;
		}
		else
			*token = new;
	}
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (0);
// 	char *s = argv[1];
// 	printf("ft_strndup: %s\n", ft_strndup(s, atoi(argv[2])));
// 	printf("   strndup: %s\n", strndup(s, atoi(argv[2])));
// 	return (0);
// }