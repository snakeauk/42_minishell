/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:13:46 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/01 03:13:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array3(void ***array)
{
	size_t	size;
	size_t	index;

	size = 0;
	if (!array)
		return ;
	while (array[size] != NULL)
	{
		index = 0;
		while (array[size][index] != NULL)
		{
			free(array[size][index]);
			index++;
		}
		free(array[size]);
		size++;
	}
	free(array);
}
