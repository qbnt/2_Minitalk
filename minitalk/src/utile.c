/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:32:24 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/13 10:56:30 by qbanet           ###   ########.fr       */
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

void	ft_display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n",
		C_GRE, C_NOR);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n",
		C_GRE, C_NOR);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n",
		C_GRE, C_NOR);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: qbanet%s\n", C_RED, pid, C_NOR,
		C_GRE, C_NOR);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	ft_init_var(t_char_c *yes)
{
	(*yes).char_value = 0;
	(*yes).current_bit = 0;
	(*yes).final_str = 0;
	(*yes).i = 0;
	(*yes).receved_len = 0;
}