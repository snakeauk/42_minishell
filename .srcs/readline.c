#include "minishell.h"

int	ft_arraylen(void **array)
{
	int	len;

	if (!array)
		return (0);
	len = 0;
	while (array[len] != NULL)
		len++;
	return (len);
}
