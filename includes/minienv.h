#ifndef MINIENV_H
# define MINIENV_H


char	*value_only(char *key_pair);
char	*minienv_value(char *name, t_list *minienv);
t_list	*minienv_node(char *name, t_list *minienv);
void	minienv_update(char *name, char *value, t_list *minienv);
char	*create_keypair(char *name, char *value);

#endif