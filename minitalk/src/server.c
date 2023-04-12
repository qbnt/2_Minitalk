/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/12 13:51:59 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_display_banner(int pid)
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

void	ft_receved_strlen(int *current_bit, char **str, int *receved, int s)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += (int)ft_pow(2, *current_bit);
	if (*current_bit == 31)
	{
		*receved = 1;
		ft_printf("%d\n", len_val);
		*str = ft_calloc(len_val + 1, sizeof(char));
		*current_bit = 0;
		len_val = 0;
		return ;
	}
	(*current_bit)++;
}

static void	ft_restart_variables(int *len, char **str, int *i)
{
	*len = 0;
	if (*str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	ft_rx(int sig)
{
	static int	receved_len = 0;
	static int	char_value = 0;
	static int	current_bit = 0;
	static int	i = 0;
	static char	*final_str;

	if (!receved_len)
		ft_receved_strlen(&current_bit, &final_str, &receved_len, (int)sig);
	else
	{
		if (sig == SIGUSR2)
			char_value += (int)ft_pow((t_ll)2, (t_ll)current_bit);
		if (current_bit == 7)
		{
			final_str[i++] = char_value;
			current_bit = 0;
			if (char_value == 0)
				return (ft_restart_variables(&receved_len, &final_str, &i));
			char_value = 0;
			return ;
		}
		current_bit++;
	}
}

int	main(void)
{
	ft_display_banner(getpid());
	signal(SIGUSR1, ft_rx);
	signal(SIGUSR2, ft_rx);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
