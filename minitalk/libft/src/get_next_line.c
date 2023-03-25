/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:22:10 by quentinba         #+#    #+#             */
/*   Updated: 2023/03/23 14:08:53 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_clean_line(char *str, size_t i)
{
	char	*rest;

	rest = NULL;
	if (!str[i])
	{
		free(str);
		return (rest);
	}
	if (str[i])
		rest = ft_strdup_gnl(str, i);
	free(str);
	return (rest);
}

static char	*ft_check_line(char *str)
{
	char	*res;
	int		len;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len ++;
	if (str[len] == '\n')
		len ++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i ++;
	}
	res[i] = 0;
	return (res);
}

static char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		r;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	r = 1;
	while (r != 0 && !ft_check_gnl(str, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		if (buf)
			str = ft_strjoin_gnl(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*buf[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf[fd] = ft_read_line(fd, buf[fd]);
	res = ft_check_line(buf[fd]);
	if (buf[fd])
		buf[fd] = ft_clean_line(buf[fd], ft_strlen(res));
	return (res);
}
