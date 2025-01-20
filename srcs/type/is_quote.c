#include "type.h"

int	is_quote(char c)
{
	return (is_squote(c) || is_dquote(c));
}
