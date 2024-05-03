/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:09:12 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/03 22:59:28 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	g_bit_received;

void	handle_server_signal(int signum)
{
	if (signum == SIGUSR1)
		g_bit_received = 1;
}

void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_bit_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_bit_received)
			pause();
		i--;
	}
}

void	send_signal(int pid, const char *argv)
{
	while (*argv)
		send_char(pid, *argv++);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa_client;
	sigset_t			set_client;

	if (argc != 3)
	{
		ft_printf("Error. Correct format: ./client [PID] [string]\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1 || server_pid == 0)
	{
		ft_printf("Invalid PID: %s\n", argv[1]);
		exit(1);
	}
	sigemptyset(&set_client);
	sigaddset(&set_client, SIGUSR1);
	sigaddset(&set_client, SIGUSR2);
	sa_client = (struct sigaction){0};
	sa_client.sa_mask = set_client;
	sa_client.sa_handler = &handle_server_signal;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1
		|| sigaction(SIGUSR2, &sa_client, NULL) == -1)
	{
		ft_printf("Error setting signal handler\n");
		exit(1);
	}
	send_signal(server_pid, argv[2]);
	ft_printf("Signal sent successfully\n");
	return (0);
}
