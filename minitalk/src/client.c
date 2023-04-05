/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/05 11:25:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments !\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	ft_printf("pid : %d, str_to_send : %s\n", pid, argv[2]);
	return (0);
}
