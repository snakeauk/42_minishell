/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:14:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputi(int num, int fd)
{
	long long	lnum;
	int			ret;
	int			wret;

	ret = 0;
	lnum = (long long)num;
	if (num < 0)
	{
		wret = ft_fputc('-', fd);
		if (wret < 0)
			return (-1);
		lnum *= -1;
		ret += wret;
	}
	wret = ft_uitoa_base((unsigned int)lnum, BASE_10, fd);
	if (wret < 0)
		return (-1);
	ret += wret;
	return (ret);
}
