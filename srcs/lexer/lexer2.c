#include "lexer.h"

t_token_type	lexer_pipe(char **string);
t_token_type	lexer_redirect(char **string);
t_token_type	lexer_quote(char **string);

t_token_type	lexer_pipe(char **string)
{
	t_token_type	type;

	if (is_pipe(**string))
		type = PIPE;
	(*string)++;
	return (type);
}

t_token_type	lexer_redirect(char **string)
{
	t_token_type	type;

	if ('<' == **string)
	{
		type = REDIRECT_IN;
		(*string)++;
		if ('<' == **string)
		{
			type = HEREDOC;
			(*string)++;
		}
	}
	else if ('>' == **string)
	{
		type = REDIRECT_OUT;
		(*string)++;
		if ('>' == **string)
		{
			type = REDIRECT_APPEND;
			(*string)++;
		}
	}
	return (type);
}

t_token_type	lexer_quote(char **string)
{
	t_token_type	type;
	char 			quote;

	if (is_dquote(**string))
		type = DQUOTE;
	else
		type = SQUOTE;
	quote = **string;
	(*string)++;
	while (*string && **string)
	{
		if (**string == quote)
		{
			(*string)++;
			return (type);
		}
		(*string)++;
	}
	ft_dprintf(STDERR_FILENO, "minishell: syntax error\n");
	type = ERROR;
	return (type);
}
