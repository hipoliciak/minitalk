/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:09:12 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/07 18:29:42 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	g_bit_received;

static void	exit_with_status(const char *message, int code)
{
	ft_printf("%s\n", message);
	exit(code);
}

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

void	send_message(int pid, const char *argv)
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
		exit_with_status("Error. Correct format: ./client [PID] [string]", 1);
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1 || server_pid == 0)
		exit_with_status("Error. Invalid PID", 1);
	sigemptyset(&set_client);
	sigaddset(&set_client, SIGUSR1);
	sa_client = (struct sigaction){0};
	sa_client.sa_handler = &handle_server_signal;
	sa_client.sa_mask = set_client;
	sa_client.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1)
		exit_with_status("Error setting signal handler", 1);
	send_message(server_pid, argv[2]);
	ft_printf("Message sent\n");
	return (0);
}
