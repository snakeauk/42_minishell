#include "minishell.h"

void sigint_handler(int sig) {
    rl_on_new_line();
    rl_replace_line("", 0);
    printf("\n");
    rl_redisplay();
}

int main(int argc, char **argv, char **envp)
{
    int ret;
    t_minishell *minishell;

    ret = 0;
    if (argc != 1)
    {
        printf("Error: invalid argments.\n");
        exit(EXIT_FAILURE);
    }
    minishell = init_minishell(envp);
    if (!minishell)
        exit(EXIT_FAILURE);
    signal(SIGINT, sigint_handler);
    ret = ft_readline(minishell);
    free_minishell(&minishell);
    return (ret);
}
// -------------------------------builtin debug--------------------------------------------
// #include "ft_builtins.h"
// // cc -I ../../includes -I ../../libft/linux/includes -I ../../libft/includes  main.c cd.c ../../libft/libft.a -o cmd
// int main(int argc, char **argv)
// {
//     // return (builtin_echo(argc, argv));
//     return (builtin_cd(argc, argv));
//     // return (builtin_pwd(argc, argv));
// }
// -----------------------------------------------------------------------------------------
