/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/17 10:07:02 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pending = 1;

static void	ft_receved(int sig, siginfo_t *info, void *nfc)
{
	(void) nfc;
	(void) info;
	if (sig == SIGUSR1)
		g_pending = 0;
	else
	{
		ft_printf("\n%sReceved Message !%s \n\n", C_YEL, C_NOR);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_send_next_char(unsigned char c, int s_pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		g_pending = 1;
		if (c & 0x01)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		c = c >> 1;
		while (g_pending)
		{
			usleep(WAIT_TIME);
		}
	}
}

static void	ft_send_len(int len, int s_pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		g_pending = 1;
		if (len & 0x01)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		len = len >> 1;
		while (g_pending)
			usleep(WAIT_TIME);
	}
}

static int	ft_error_in_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (-1);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("1234567890", argv[1][i]))
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int					s_pid;
	char				*str_to_send;
	int					len;
	int					i;
	struct sigaction	c_act;

	c_act.sa_flags = SA_SIGINFO;
	c_act.sa_sigaction = ft_receved;
	if (ft_error_in_args(argc, argv))
		return (-1);
	s_pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	len = ft_strlen(str_to_send);
	i = -1;
	sigaction(SIGUSR1, &c_act, NULL);
	sigaction(SIGUSR2, &c_act, NULL);
	ft_send_len(len, s_pid);
	while (str_to_send[++i])
		ft_send_next_char(str_to_send[i], s_pid);
	ft_send_next_char(str_to_send[i], s_pid);
	while (1)
		usleep(WAIT_TIME);
}
