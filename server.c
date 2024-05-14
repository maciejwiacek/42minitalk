/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:22:01 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/14 11:26:00 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	convert_to_char(int bit)
{
	static int i = 0;
	static char c = 0;
	if (i < 8)
	{
		c |= bit << (7 - i);
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		convert_to_char(1);
	else
		convert_to_char(0);
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID is: %d\n", getpid());
	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep (1);
	}
	return (0);
}
