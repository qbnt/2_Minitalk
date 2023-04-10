/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/10 12:02:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_error(int argc)
{
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments !\n");
		return ;
	}
}

static void	ft_received(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d\n", received);
		exit(0);
	}
}

static void	ft_tx(int s_pid, char *str)
{
	int		i;
	char	c;
	char	n;

	n = '\n';
	while (*str)
	{
		i = 8;
		c = *str++;
		while (i --)
		{
			if (c >> i & 1)
				kill(s_pid, SIGUSR2);
			else
				kill(s_pid, SIGUSR1);
			usleep(1500);
		}
	}
	i = 8;
	while (i --)
	{
		if (n >> i & 1)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		usleep(50);
	}
	i = 8;
	while (i --)
	{
		kill(s_pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		s_pid;

	s_pid = ft_atoi(argv[1]);
	ft_error(argc);
	signal(SIGUSR1, ft_received);
	signal(SIGUSR2, ft_received);
	ft_tx(s_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
