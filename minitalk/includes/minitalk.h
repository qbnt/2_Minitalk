/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:02:47 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/12 17:31:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

# define WAIT_TIME 50

typedef struct s_char_c
{
	int		receved_len = 0;
	int		char_value = 0;
	int		current_bit = 0;
	int		i = 0;
	char	*final_str;
}	t_char_c;


long long	ft_pow(long long nb, long long p);

#endif
