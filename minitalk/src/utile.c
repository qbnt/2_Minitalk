/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:32:24 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/22 18:44:37 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	while (*str ++)
		i ++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		ft_putchar(*str++, fd);
}

void	ft_putnbr_fd(int n, int fd)
{	
	if (n < 0)
	{
		if (n == -2147483648)
			write (fd, "-2147483648", 11);
		else
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	if (n > 9)
	{
		if (n == 0)
			return ;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}	
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	return (res);
}
