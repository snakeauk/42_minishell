#include "debug.h"

int	debug_lexer(t_token **token)
{
	int		ret;
	t_token	*cur;

	if (!token || !*token)
		return (0);
	ret = 0;
	printf("\
    0 : WORD, \n \
    1 : PIPE, \n \
    2 : REDIRECT_IN, \n \
    3 : REDIRECT_OUT, \n \
    4 : REDIRECT_APPEND, \n \
    5 : HEREDOC, \n \
    6 : SQUOTE, \n \
    7 : DQUOTE, \n \
    8 : SENTINEL, \n \
    9 : ERROR\n");
	printf("==============================\n");
	cur = *token;
	while (cur)
	{
		printf("%d:\t%d:\t%s\n", ret + 1, cur->type, cur->string);
		cur = cur->next;
		ret++;
	}
	return (ret);
}
