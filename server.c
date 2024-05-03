/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:09:40 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/03 23:00:08 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	g_message_received;

void	handle_client_signal(int signum, siginfo_t *siginfo, void *other)
{
	static char	character;
	static int	bit_count;

	(void)other;
	g_message_received = 0;
	if (signum == SIGUSR1)
		character |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
			g_message_received = 1;
		bit_count = 0;
		character = 0;
	}
	character <<= 1;
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
	{
		ft_printf("Error sending signal to client\n");
		exit(1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa_server;	
	sigset_t			set_server;

	sigemptyset(&set_server);
	sigaddset(&set_server, SIGUSR1);
	sigaddset(&set_server, SIGUSR2);
	sa_server = (struct sigaction){0};
	sa_server.sa_mask = set_server;
	sa_server.sa_sigaction = &handle_client_signal;
	sa_server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1
		|| sigaction(SIGUSR2, &sa_server, NULL) == -1)
	{
		ft_printf("Error setting signal handler\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for signals...\n");
	while (1)
	{
		if (g_message_received == 1)
			ft_printf("\nMessage received. Waiting for new signals...\n");
		pause();
	}
	return (0);
}
