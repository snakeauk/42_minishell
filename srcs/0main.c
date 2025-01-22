#include "minishell.h"

void	sigint_handler(int sig)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

int	ft_readline(t_minishell *minishell)
{
	int	ret;

	ret = 0;
	rl_clear_history();
	while (1)
	{
		init_line(minishell);
		minishell->line = readline("minishell$ ");
		if (!*minishell->line)
			continue ;
		add_history(minishell->line);
		minishell->token = ft_lexer(minishell->line);
		print_token(minishell->token);
		if (minishell->token == NULL)
			continue ;
		minishell->ast = ft_parser(minishell->token);
		if (minishell->ast == NULL)
			continue ;
		// print_ast(minishell->ast);
	}
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	int ret;
	t_minishell *minishell;

	ret = 0;
	if (argc != 1)
		return (printf("Error: invalid argments.\n"), 1);

	minishell = init_minishell(envp);
	if (!minishell)
		exit(EXIT_FAILURE);
	signal(SIGINT, sigint_handler);
	ret = ft_readline(minishell);
	free_minishell(minishell);
	return (ret);
}