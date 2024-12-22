/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:08:10 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/22 03:33:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

int		main(void);
void	handle_signal(int sig, siginfo_t *info, void *context);

#endif