/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:14:04 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/01 03:14:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array2(void **array)
{
	size_t	index;

	index = 0;
	if (!array)
		return ;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}
