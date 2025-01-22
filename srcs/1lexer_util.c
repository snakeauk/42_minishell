#include "minishell.h"

t_token	*token_new(char *string, t_token_type type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->string = string;
	token->type = type;
	token->next = NULL;
	return (token);
}

void	append_token(t_token **tokens, char *string, t_token_type type)
{
	t_token	*head;
	t_token	*new_token;

	new_token = token_new(string, type);
	head = *tokens;
	if (*tokens == NULL)
	{
		// リストが空の場合は最初のトークンとして設定
		*tokens = new_token;
	}
	else
	{
		// リストの最後まで進み、最後のトークンの next に新しいトークンを設定
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = new_token;
	}
}
/**
 * @return quotationが見つからなかったら1を返す
 * @return　正常でquoteまでincrementして0を返す
 */
int	skip_while_next_quote(char *input, int *next_word_len)
{
	char	quote;

	quote = input[*next_word_len];
	(*next_word_len)++;
	while (quote != input[*next_word_len])
	{
		if (input[*next_word_len] == '\0')
			return (1);
		(*next_word_len)++;
	}
	return (0);
}

// void	free_token(t_token **token)
// {
// 	t_token	*cur;
// 	t_token	*next;

// 	if (!token || !*token)
// 		return ;
// 	cur = *token;
// 	while (cur)
// 	{
// 		next = cur->next;
// 		if (cur->string)
// 			free(cur->string);
// 		free(cur);
// 		cur = next;
// 	}
// 	*token = NULL;
// }

/*
cc srcs/debug.c srcs/1lexer_util.c  -I./includes -I./libft/linux/includes
	-I./libft/includes  libft/libft.a
int	main(void)
{
	t_token	*tmp;

	t_token *tokens = NULL; // 空のリスト
	// トークンを追加
	append_token(&tokens, ft_strdup("echo"), WORD);
	append_token(&tokens, ft_strdup("|"), PIPE);
	append_token(&tokens, ft_strdup("ls"), WORD);
	append_token(&tokens, ft_strdup(">"), REDIRECT_OUT);
	append_token(&tokens, ft_strdup("output.txt"), WORD);
	// リストの内容を表示
	print_token(tokens);
	// メモリ解放（通常はメモリリークを防ぐために行う）
	free_token(&tokens);
	return (0);
} */
