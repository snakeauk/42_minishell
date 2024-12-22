/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:12:10 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 23:50:06 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	size;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	size = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + len + 1));
	if (!str)
		return (NULL);
	index = -1;
	while (++index < len)
		str[index] = s1[index];
	index = -1;
	while (++index < size)
		str[index + len] = s2[index];
	str[len + size] = '\0';
	return (str);
}
