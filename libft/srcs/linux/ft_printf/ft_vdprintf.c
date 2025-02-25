/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:32 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 18:42:48 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	ret;
	int	wret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			wret = ft_printf_switch(format, ap, fd);
			if (wret < 0)
				return (-1);
			ret += wret;
		}
		else
		{
			wret = ft_fputc(*format, fd);
			if (wret < 0)
				return (-1);
			ret += wret;
		}
		format++;
	}
	return (ret);
}
