/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 18:39:22 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pow(long double nb, long double p)
{
	long double	result;

	result = nb;
	while (p-- > 1)
		result *= nb;
	return (result);
}
