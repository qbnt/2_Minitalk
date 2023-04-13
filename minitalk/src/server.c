/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/13 11:31:08 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_char_c	yes;

static void	ft_rest_var(t_char_c *yes)
{
	(*yes).receved_len = 0;
	if ((*yes).final_str)
	{
		ft_printf("%s\n", (*yes).final_str);
		free((*yes).final_str);
		(*yes).char_value = 0;
	}
	(*yes).i = 0;
}

static void	ft_receved_strlen(t_char_c *yes, int s, pid_t c_pid)
{
	static int	len_val = 0;

	kill(c_pid, SIGUSR1);
	if (s == SIGUSR2)
		len_val += (int)ft_pow(2, (*yes).current_bit);
	if ((*yes).current_bit == 31)
	{
		(*yes).receved_len = 1;
		ft_printf("%d\n", len_val);
		(*yes).final_str = ft_calloc(len_val + 1, sizeof(char));
		(*yes).current_bit = 0;
		len_val = 0;
		return ;
	}
	((*yes).current_bit)++;
}

static void	ft_rx(int sig, siginfo_t *info, void *idc)
{
	(void) idc;
	if (!yes.receved_len)
		ft_receved_strlen(&yes, (int)sig, info->si_pid);
	else
	{
		if (sig == SIGUSR2)
			yes.char_value += (int)ft_pow(2, yes.current_bit);
		if (yes.current_bit == 7)
		{
			yes.final_str[yes.i++] = yes.char_value;
			yes.current_bit = 0;
			if (yes.char_value == 0)
			{
				kill(info->si_pid, SIGUSR2);
				return (ft_rest_var(&yes));
			}
			yes.char_value = 0;
			return ;
		}
		yes.current_bit++;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_act;

	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = ft_rx;
	ft_init_var(&yes);
	ft_display_banner(getpid());
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
