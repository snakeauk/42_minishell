/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:53 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/22 03:36:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	bit = 0;
	c = 0;
	(void)context;
	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_fputs("", STDOUT_FILENO);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(STDOUT_FILENO, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Minitalk server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
}
