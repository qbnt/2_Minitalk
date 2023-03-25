/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:37:51 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 18:39:18 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(t_ll num, const char *base_set, int base)
{
	char	*tmp;
	char	*result;

	if (num < 0)
	{
		tmp = ft_convert_base_unsigned(-num, base_set, base);
		result = ft_strjoin("-", tmp);
		free(tmp);
		return (result);
	}
	else
		return (ft_convert_base_unsigned(num, base_set, base));
}
