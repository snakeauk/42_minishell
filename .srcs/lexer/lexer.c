#include "lexer.h"

t_token **lexer(char *input);
void	lexer_reserved_word(t_token **token, char **string);

void	lexer_reserved_word(t_token **token, char **string)
{
	t_token_type	type;
	char			*start;
	
	start = *string;
	if (ft_isspace(**string))
	{
		(*string)++;
		return ;
	}
	else if (is_pipe(**string))
		type = lexer_pipe(string);
	else if (is_redirect(**string))
		type = lexer_redirect(string);
	else if (is_dquote(**string) || is_squote(**string))
		type = lexer_quote(string);
	if (type == ERROR)
	{
		free_token(token);
		token = NULL;
		return ;
	}
	append_token(token, init_token_node(ft_strndup(start, (size_t)(*string - start)), type));
}

t_token **lexer(char *input)
{
	t_token 		**token;
	char			*start;

	token = (t_token **)malloc(sizeof(t_token *));
	if (!token)
	{
		perror("lexer");
		return (NULL);
	}
	*token = NULL;
	start = input;
	while (input && *input)
	{
		// *inputに予約語がきたら...
		if (is_pipe(*input) || is_redirect(*input) || is_dquote(*input) || is_squote(*input) || ft_isspace(*input))
		{
			// inputまでをリストに追加
			if (input != start)
				append_token(token, init_token_node(ft_strndup(start, input - start), WORD));
			lexer_reserved_word(token, &input);
			if (!token)
				return (NULL);
			start = input;
		}
		else
			input++;
	}
	if (input != start)
		append_token(token, init_token_node(ft_strndup(start, input - start), WORD));
	return (token);
}
