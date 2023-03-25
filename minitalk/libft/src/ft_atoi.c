/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:41:48 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/05 10:11:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	sign = 1;
	nbr = 0;
	while ((*str >= 7 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str ++;
	while (*str >= '0' && *str <= '9')
		nbr = (((int)*str++ - 48) + nbr * 10);
	return (nbr * sign);
}
