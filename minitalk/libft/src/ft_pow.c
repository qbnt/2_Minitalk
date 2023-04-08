/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/08 15:20:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pow(long double nb, long double p)
{
	if (p < 0)
		return (0);
	else if (p == 0 && p == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, p - 1));
}
