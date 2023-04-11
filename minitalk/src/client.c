/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/11 17:13:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pending = 1;

static void	ft_received(int sig, siginfo_t *info, void *context)
{
	(void) context;
	(void) info->si_pid;
	if (sig == SIGUSR1)
		g_pending = 0;
}

static void	ft_tx(int s_pid, char *str)
{
	int		i;
	char	c;

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
			while (g_pending)
				usleep(WAIT_TIME);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	c_act;
	int					s_pid;

	c_act.sa_flags = SA_SIGINFO;
	c_act.sa_sigaction = ft_received;
	s_pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments !\n");
		return (-1);
	}
	sigaction(SIGUSR1, &c_act, NULL);
	ft_tx(s_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
