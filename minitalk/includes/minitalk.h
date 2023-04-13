/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:02:47 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/13 12:18:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

# define WAIT_TIME 50

typedef struct s_char_c
{
	int		receved_len;
	int		char_value;
	int		current_bit;
	int		i;
	char	*final_str;
}	t_char_c;


long long	ft_pow(long long nb, long long p);
void		ft_display_banner(int pid);
void		ft_init_var(t_char_c *yes);

#endif
