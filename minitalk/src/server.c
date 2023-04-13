/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/13 14:42:11 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_char_c	g_yes;

static void	ft_rest_var(void)
{
	g_yes.receved_len = 0;
	if (g_yes.final_str)
	{
		ft_printf("%s\n", g_yes.final_str);
		free(g_yes.final_str);
		g_yes.char_value = 0;
	}
	g_yes.i = 0;
}

static void	ft_receved_strlen(int s, pid_t c_pid)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += (int)ft_pow(2, g_yes.current_bit);
	if (g_yes.current_bit == 31)
	{
		g_yes.receved_len = 1;
		ft_printf("%d\n", len_val);
		g_yes.final_str = ft_calloc(len_val + 1, sizeof(char));
		g_yes.current_bit = 0;
		len_val = 0;
		kill(c_pid, SIGUSR1);
		return ;
	}
	(g_yes.current_bit)++;
	kill(c_pid, SIGUSR1);
}

static void	ft_charset(char *str, siginfo_t *info)
{
	str[g_yes.i++] = g_yes.char_value;
	g_yes.current_bit = 0;
	if (g_yes.char_value == 0)
	{
		kill(info->si_pid, SIGUSR2);
		return (ft_rest_var());
	}
	g_yes.char_value = 0;
	kill((*info).si_pid, SIGUSR1);
	return ;
}

static void	ft_rx(int sig, siginfo_t *info, void *idc)
{
	char	*str;

	(void) idc;
	str = g_yes.final_str;
	if (!g_yes.receved_len)
		ft_receved_strlen(sig, info->si_pid);
	else
	{
		if (sig == SIGUSR2)
			g_yes.char_value += (int)ft_pow(2, g_yes.current_bit);
		if (g_yes.current_bit == 7)
			return (ft_charset(str, info));
		g_yes.current_bit++;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_act;

	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = ft_rx;
	ft_init_var(&g_yes);
	ft_display_banner(getpid());
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
