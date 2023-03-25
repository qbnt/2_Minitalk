/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/25 14:17:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_msg(int pid, char *str_to_send)
{
	ft_printf("%d", pid);
	ft_printf("%s", str_to_send);
}

int	main(int argc, char **argv)
{
	char	*str_to_send;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Error, wrongs numburs of arguments");
	}

	pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	ft_send_msg(pid, str_to_send);
	return (0);
}