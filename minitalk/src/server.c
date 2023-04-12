/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/12 17:31:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n",
		C_GRE, C_NOR);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n",
		C_GRE, C_NOR);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: qbanet%s\n", C_RED, pid, C_NOR,
		C_GRE, C_NOR);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	ft_receved_strlen(t_char_c *yes, int s, int c_pid)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += (int)ft_pow(2, *yes.current_bit);
	if (*yes.current_bit == 31)
	{
		*yes.receved = 1;
		ft_printf("%d\n", len_val);
		*yes.str = ft_calloc(len_val + 1, sizeof(char));
		*yes.current_bit = 0;
		len_val = 0;
		return ;
	}
	kill(SIGUSR1, c_pid);
	(*yes.current_bit)++;
}

static void	ft_rest_var(int *len, char **str, int *i)
{
	*len = 0;
	if (*str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	ft_rx(int sig, siginfo_t *info, void *idc)
{
	static t_char_c	yes;

	(void) idc;
	if (!yes.receved_len)
		ft_receved_strlen(&yes, (int)sig, info->si_pid);
	else
	{
		if (sig == SIGUSR2)
			yes.char_value += (int)ft_pow((t_ll)2, (t_ll)yes.current_bit);
		if (yes.current_bit == 7)
		{
			yes.final_str[i++] = yes.char_value;
			yes.current_bit = 0;
			if (yes.char_value == 0)
			{
				kill(SIGUSR2, info->si_pid);
				return (ft_rest_var(&yes.receved_len, &yes.final_str, &yes.i));
			}
			yes.char_value = 0;
			return ;
		}
		yes.current_bit++;
	}
	kill(SIGUSR1, info->si_pid);
}

int	main(void)
{
	struct sigaction	s_act;

	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = ft_rx;
	ft_display_banner(getpid());
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
