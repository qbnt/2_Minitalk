/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/25 14:30:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_input(void)
{
	return (1);
}

int	ft_confirm(void)
{
	return (1);
}

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("Welcome to your Minitalk server.\nYour PID is :", 1);
	ft_putnbr_fd(pid, 1);
	while (!ft_input())
	{
		
	}
	if (ft_input())
		ft_confirm();
	return (0);
}