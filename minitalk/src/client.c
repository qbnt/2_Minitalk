/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/26 15:14:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	char	*str_to_send;
	int		pid;

	if (argc != 3)
	{
		ft_printf("Error, wrongs numburs of arguments.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	ft_printf("pid : %d, str_to_send : %s \n", pid, str_to_send);
	return (0);
}