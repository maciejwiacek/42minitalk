/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:22:04 by mwiacek           #+#    #+#             */
/*   Updated: 2024/05/14 13:43:24 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "Libftprintf/includes/libft.h"
#include "Libftprintf/includes/printf.h"

void	send_message(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (((*str >> i) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Pid is %d\n", pid);
		if (!pid)
		{
			ft_printf("Make sure you put correct PID!\n");
			return (0);
		}
		str = argv[2];
		send_message(pid, str);
	}
	else
	{
		ft_printf("Make sure you put PID and message!\n");
	}
}
