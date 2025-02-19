#ifndef MINIENV_H
# define MINIENV_H


char	*value_only(char *key_pair);
char	*minienv_value(char *name, t_list *minienv);
t_list	*minienv_node(char *name, t_list *minienv);

#endif