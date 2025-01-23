#include "lexer.h"

t_token_type	lexer_pipe(char **string);
t_token_type	lexer_redirect(char **string);
t_token_type	lexer_quote(char **string);

t_token_type	lexer_pipe(char **string)
{
	t_token_type	type;

	if (is_pipe(**string))
		type = PIPE;
	return (type);
}

t_token_type	lexer_redirect(char **string)
{
	t_token_type	type;

	if (ft_strncmp("<<", *string, 2) == 0 || ft_strncmp(">>", *string, 2) == 0)
	{
		if (ft_strncmp("<<", *string, 2) == 0)
			type = HEREDOC;
		else if (ft_strncmp(">>", *string, 2) == 0)
			type = REDIRECT_APPEND;
		(*string)++;
	}
	else if (ft_strncmp("<", *string, 1) == 0)
		type = REDIRECT_IN;
	else if (ft_strncmp(">", *string, 1) == 0)
		type = REDIRECT_OUT;
	return (type);
}
