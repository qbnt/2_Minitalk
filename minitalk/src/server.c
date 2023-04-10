/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/10 10:36:49 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", C_GRE, C_NOR);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", C_GRE, C_NOR);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", C_GRE, C_NOR);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", C_GRE, C_NOR);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", C_GRE, C_NOR);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: qbanet%s\n", C_RED, pid, C_NOR,
		C_GRE, C_NOR);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

static  void	ft_rx(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			c_pid = 0;
	static unsigned char	c = 0;

	(void) context;
	if (!c_pid)
		c_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(c_pid, SIGUSR2);
			c_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(c_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_act;
	int					s_pid;

	s_pid = getpid();
	ft_display_banner(s_pid);
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = ft_rx;
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	while (1)
		pause();
	return (0);
}
