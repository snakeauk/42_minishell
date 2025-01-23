#include "parser.h"
#include "debug.h"

t_ast	*ast_init_node(void)
{
	t_ast	*new;

	new = (t_ast *)ft_calloc(1, sizeof(t_ast));
	if (!new)
	{
		perror("init_ast_node");
		return (NULL);
	}
	new->token = NULL;
	new->redirect = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_ast *parse_statement(t_token **tokens)
{
    t_ast	        *ast;
    t_token         *current;
    t_token_type    type;

    ast = ast_init_node();
    while (*tokens && (*tokens)->type != PIPE)
    {
        current = *tokens;
        *tokens = (*tokens)->next;
        if (current->type == REDIRECT_IN || current->type == REDIRECT_OUT || current->type == REDIRECT_APPEND || current->type == HEREDOC)
        {
            if (*tokens && (*tokens)->type == WORD)
            {
                type = current->type;
				token_append(&ast->redirect, token_init_node(ft_strdup((*tokens)->string), type));
				*tokens = (*tokens)->next;
            }
            else
            {
                if (!*tokens)
                    ft_dprintf(STDERR_FILENO, "minishell: syntax error near unexpected token `newline'\n");
                else
                    ft_dprintf(STDERR_FILENO, "minishell: syntax error near unexpected token `%s'\n", (*tokens)->string);
				free_ast(&ast);
                return (NULL);
            }
        }
        else
            token_append(&ast->token, token_init_node(ft_strdup(current->string), WORD));
    }
    return (ast);
}

t_ast *parser(t_token *tokens)
{
    t_ast   *root;
    t_ast   *ast;
    t_ast   *right_node;
    t_ast   *new_root;

    ast = parse_statement(&tokens);
    if (!ast)
        return (NULL);
    while (tokens && tokens->type == PIPE)
    {
        tokens = tokens->next;
        right_node = parse_statement(&tokens);
        if (!right_node)
        {
            ft_putstr_fd("syntax error: expected a WORD after pipe\n", STDERR_FILENO);
			free_ast(&ast);
            return (NULL);
        }
        new_root = ast_init_node();
        token_append(&new_root->token, token_init_node(ft_strdup("|"), PIPE));
        new_root->left = ast;
        new_root->right = right_node;
		ast = new_root;
    }
    return (ast);
}

// t_ast *parser(t_token *tokens)
// {
// 	t_ast *ast;

// 	LOG;
// 	ast = parse_line(tokens);
// 	if (!ast)
// 		return (NULL);
// 	LOGOUT;
// 	return (ast);
// }

/*
// t_ast *init_ast_node(t_token **token);
// void add_ast(t_ast **ast, t_token **token);
// t_ast **parser(t_token **token);

// t_ast *init_ast_node(t_token **token)
// {
//     t_ast *new;

//     new = (t_ast *)ft_calloc(1, sizeof(t_ast));
//     if (!new)
//     {
//         perror("init_ast");
//         return (NULL);
//     }
//     new->token = *token;
//     new->redirect = NULL;
//     new->left = NULL;
//     new->right = NULL;
//     return (new);
// }

// void add_ast(t_ast **ast, t_token **token)
// {
//     t_ast *new;

//     new = init_ast_node(token);
//     if (!new)
//     {
//         free_ast(ast);
//         return;
//     }
// 	if (!ast || !*ast)
// 		ast = &new;
// 	else
// 	{
// 		if ((*token)->type == PIPE)
// 		{
// 			new->left = *ast;
// 			*ast = new; // 新しいノードが根ノードになる
// 		}
// 		else
// 		{
// 			if (!(*ast)->left)
// 				(*ast)->left = new;
// 			else
// 				(*ast)->right = new;
// 		}
// 	}
// }

// t_ast **parser(t_token **token)
// {
//     t_ast	**ast;
//     t_token	*current_token;
//     t_token	*token_start;

//     if (!token || !(*token))
//         return (NULL);
// 	ast = NULL;
//     token_start = *token;
//     while (*token)
//     {
//         current_token = *token;
//         *token = (*token)->next;
//         if (current_token->type == PIPE || current_token->type == REDIRECT_IN ||
//             current_token->type == REDIRECT_OUT || current_token->type == REDIRECT_APPEND ||
//             current_token->type == HEREDOC)
//         {
//             current_token->next = NULL;
//             add_ast(ast, &token_start);
//             if (!*ast)
// 			{
// 				free_token(token);
//                 return (NULL);
// 			}
//             add_ast(ast, &current_token);
//             if (!*ast)
// 			{
// 				free_token(token);
//                 return (NULL);
// 			}
//             token_start = *token;
//         }
//     }
//     if (token_start != *token)
//     {
//         add_ast(ast, &token_start);
//         if (!*ast)
// 		{
// 			free_token(token);
//             return (NULL);
// 		}
//     }
//     return (ast);
// }
*/