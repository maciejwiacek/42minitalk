/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:22:01 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/15 16:06:35 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "Libftprintf/includes/libft.h"
#include "Libftprintf/includes/printf.h"

void	convert_to_char(int pid, int bit)
{
	static int	i = 0;
	static char	c = 0;

	if (i < 8)
	{
		c |= bit << (7 - i);
		i++;
	}
	if (i == 8)
	{
		if (c == '\0' && pid)
			kill(pid, SIGUSR1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	sig_action(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		convert_to_char(info->si_pid, 1);
	else if (signum == SIGUSR2)
		convert_to_char(info->si_pid, 0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &sig_action;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
