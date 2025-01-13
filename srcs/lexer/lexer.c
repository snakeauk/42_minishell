#include "lexer.h"

// Free list of t_token.
t_token *free_token(t_token **token)
{
    t_token *cur;

    while (*token)
    {
        cur = (*token);
        (*token) = (*token)->next;
        if (cur->value)
            free(cur->value);
        if (cur)
            free(cur);
    }
    token = NULL;
    return (NULL);
}

// Create new t_token from value and type. 
t_token *create_token(const char *value, t_token_type type)
{
    t_token *token;
    
    token = (t_token *)malloc(sizeof(t_token));
    if (!token)
    {
        perror("Error: create_token");
        return (NULL);
    }
    token->value = ft_strdup(value);
    token->type = type;
    token->next = (NULL);
    return (token);
}

t_token_type identify_token_type(const char *str)
{
    if (ft_strlen(str) > 2)
    {
        if (ft_strcmp(str, ">>") == 0)
            return REDIRECT_APPEND;
        else if (ft_strcmp(str, "<<") == 0)
            return HEREDOC;
    }
    if (cmp(str, "|") == 0)
        return PIPE;
    else if (ft_strcmp(str, "<") == 0)
        return REDIRECT_IN;
    else if (ft_strcmp(str, ">") == 0)
        return REDIRECT_OUT;
    else if (ft_strcmp(str, "'") == 0)
        return DQUOTE;
    else if (ft_strcmp(str, "\"") == 0)
        return DQUOTE;
    else if (str[0] == '$')
        return VARIABLE;
    else
        return WORD; // is the default
}

t_token *lexer(const char *input)
{
    t_token *head;
    t_token *current;
    char buffer[1024];
    int i;
    int buf_index;

    head = NULL;
    current = NULL;
    i = 0;
    buf_index = 0;
    if (!input)
        return (NULL);
    while (input[i])
    {
        if (ft_isspace(input[i])) {
            i++;
            continue;
        }

        // Process of particular character
        if (ft_strchr("|<>$; ", input[i]))
        {
            if (buf_index > 0)
            {
                buffer[buf_index] = '\0';
                t_token *token = create_token(buffer, WORD);
                if (!head)
                    head = current = token;
                else {
                    current->next = token;
                    current = token;
                }
                buf_index = 0;
            }

            // Create new token
            buffer[0] = input[i++];
            buffer[1] = '\0';
            t_token_type type = identify_token_type(buffer);
            t_token *token = create_token(buffer, type);
            if (!head)
                head = current = token;
            else {
                current->next = token;
                current = token;
            }
            continue;
        }

        // Add char array in buffer
        buffer[buf_index++] = input[i];
        i++;
    }

    // Decide last token
    if (buf_index > 0) {
        buffer[buf_index] = '\0';
        t_token *token = create_token(buffer, WORD);
        if (!head)
            head = token;
        else
            current->next = token;
    }

    return head;
}