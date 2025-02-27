#ifndef	INIT_H
#define	INIT_H

#include "struct.h"
#include "libft.h"
#include "minienv.h"

t_minishell *init_minishell(char **envp);
void list_append(char *key_pair, t_list **list);

#endif