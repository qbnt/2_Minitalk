/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:32:24 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/12 11:03:35 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long long	ft_pow(long long nb, long long p)
{
	if (p < 0)
		return (0);
	else if (p == 0 && p == 0)
		return (1);
	else
		return (nb * ft_pow(nb, p - 1));
}
