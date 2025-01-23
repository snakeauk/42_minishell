#include "lexer.h"
#include "debug.h"

void	lexer_meta(t_token **token, char **string)
{
	t_token_type	type;
	char			*start;
	
	start = *string;
	if (ft_isspace(**string))
		return ;
	else if (is_pipe(**string))
		type = lexer_pipe(string);
	else if (is_redirect(**string))
		type = lexer_redirect(string);
	if (type == ERROR)
	{
		free_token(token);
		token = NULL;
		return ;
	}
	append_token(token, init_token_node(ft_strndup(start, (size_t)(*string + 1 - start)), type));
}

void	lexer_search_quote(t_token **token, char **string)
{
	char			quote;

	LOG;
	if (!string || !*string)
	{
		ft_dprintf(STDERR_FILENO, "minishell: syntax error\n");
		free_token(token);
		return ;
	}
	quote = **string;
	(*string)++;
	while (**string && quote != **string)
		(*string)++;
	if (**string == '\0')
	{
		ft_dprintf(STDERR_FILENO, "minishell: syntax error\n");
		free_token(token);
		return ;
	}
	LOGOUT;
}

t_token *lexer(char *input)
{
	t_token 		*token;
	char			*start;

	LOG;
	token = NULL;
	start = input;
	while (*input)
	{
		// *inputに予約語がきたら...
		if (ft_isspace(*input) || is_pipe(*input) || is_redirect(*input))
		{
			// inputまでをリストに追加
			if (input != start)
				append_token(&token, init_token_node(ft_strndup(start, input - start), WORD));
			lexer_meta(&token, &input);
			if (!token)
				return (NULL);
			start = input + 1;
		}
		else if (is_dquote(*input) || is_squote(*input))
		{
			lexer_search_quote(&token, &input);
			if (!*input)
			{
				return (NULL);
			}
		}
		input++;
	}
	if (input != start)
		append_token(&token, init_token_node(ft_strndup(start, input - start), WORD));
	LOGOUT;
	return (token);
}
