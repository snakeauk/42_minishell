#include "libft.h"

char *ft_strndup(const char *s, size_t n)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, n + 1);
	return (str);
}
