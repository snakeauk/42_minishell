/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:07:49 by kinamura          #+#    #+#             */
/*   Updated: 2024/12/22 03:44:49 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_sendc(const pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending SIGUSR2");
				exit(EXIT_FAILURE);
			}
		}
		bit--;
		usleep(600);
	}
}

void	ft_sends(const pid_t pid, char *str)
{
	while (*str)
	{
		ft_sendc(pid, *str);
		str++;
	}
	ft_sendc(pid, '\0');
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message acknowledged by server\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./client <PID> <message>\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 3)
	{
		ft_dprintf(STDERR_FILENO, "Error: Invalid PID\n");
		return (EXIT_FAILURE);
	}
	else if (kill(pid, 0) == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error: non-existent PID\n");
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, handle_ack);
	ft_sends(pid, argv[2]);
	return (EXIT_SUCCESS);
}
