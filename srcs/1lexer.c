#include "debug.h"
#include "minishell.h"

/**
 * <>|が来た場合　特殊なtokenを返す、input のindexを進める
 */
int	process_meta_char(t_token *token, char *input, int *index)
{
	t_token_type	type;

	LOG;
	if (input[*index] == '\0')
		return (1);
	if (ft_strncmp("|", &input[*index], 1) == 0)
		type = PIPE;
	else if (ft_strncmp("<<", &input[*index], 2) == 0)
	{
		type = HEREDOC;
		(*index)++;
	}
	else if (ft_strncmp(">>", &input[*index], 2) == 0)
	{
		type = REDIRECT_APPEND;
		(*index)++;
	}
	else if (ft_strncmp("<", &input[*index], 1) == 0)
		type = REDIRECT_IN;
	else if (ft_strncmp(">", &input[*index], 1) == 0)
		type = REDIRECT_OUT;
	(*index)++;
	LOGOUT;
	append_token(&token, NULL, type);
	return (0);
}

t_token	*ft_lexer(char *input)
{
	t_token	*token;
	int		next_word_len;

	LOG;
	token = NULL;
	while (*input)
	{
		next_word_len = 0;
		while (input[next_word_len] && ft_strchr("<>|",
				input[next_word_len]) == NULL)
		{
			next_word_len++;
		}
		append_token(&token, ft_strndup(input, next_word_len), WORD);
		if (process_meta_char(token, input, &next_word_len))
			break ;
		input += next_word_len;
	}
	LOGOUT;
	return (token);
}

// t_token	**lexer(char *input)
// {
// 	t_token **token;
// 	char *start;

// 	token = (t_token **)malloc(sizeof(t_token *));
// 	if (!token)
// 	{
// 		perror("lexer");
// 		return (NULL);
// 	}
// 	*token = NULL;
// 	start = input;
// 	while (input && *input)
// 	{
// 		// *inputに予約語がきたら...
// 		if (is_pipe(*input) || is_redirect(*input) || is_dquote(*input)
// 			|| is_squote(*input) || ft_isspace(*input))
// 		{
// 			// inputまでをリストに追加
// 			if (input != start)
// 				append_token(token, init_token_node(ft_strndup(start, input
// 							- start), WORD));
// 			lexer_reserved_word(token, &input);
// 			if (!token)
// 				return (NULL);
// 			start = input;
// 		}
// 		else
// 			input++;
// 	}
// 	if (input != start)
// 		append_token(token, init_token_node(ft_strndup(start, input
//			- start),
// 				WORD));
// 	return (token);
// }