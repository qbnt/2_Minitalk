/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/05 12:21:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pidprint(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Welcome to your Minitalk server.\nYour PID is : %d\n", pid);
}

/*void	ft_sigest(int sig, siginfo_t *info, void *context)
{
	(void) context;
}
*/
int	main(void)
{
	struct sigaction	sa_serv;

	sa_serv.sa_flags = SA_SIGINFO;
	sa_serv.sa_sigaction = ft_sigest;
	ft_pidprint();
	sigaction(SIGUSR1, &ft_sigest, NULL);
	sigaction(SIGUSR2, &ft_sigest, NULL);
	while (1)
		pause();
	return (TRUE);
}
