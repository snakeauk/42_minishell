/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:56:43 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 18:41:00 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputp(unsigned long long unum, int fd)
{
	int		ret;
	int		wret;

	ret = 0;
	wret = ft_fputs("0x", fd);
	if (wret < 0)
		return (-1);
	ret += wret;
	wret = ft_ulltoa_base(unum, BASE_LOW_16, fd);
	if (wret < 0)
		return (-1);
	ret += wret;
	return (ret);
}
