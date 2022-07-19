/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:28 by lhmissi           #+#    #+#             */
/*   Updated: 2022/07/19 15:59:07 by lhmissi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_non(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
}

char	*ft_str(int fd, char *str, char *buffer)
{
	int	len;

	len = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!ft_non(str))
		len = read(fd, buffer, BUFFER_SIZE);
	while (!ft_non(str) && len != 0)
	{
		if (len == -1)
		{
			free(buffer);
			return (NULL);
		}
		str = ft_strjoin(str, buffer);
		if (ft_non(str))
			break ;
		if (!str)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		len = read(fd, buffer, BUFFER_SIZE);
	}
	if (!str || len == 0)
	{
		free (buffer);
		free (str);
		return (NULL);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*strfinal;
	char		*buffer;

	strfinal = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_str(fd, str, buffer);
	strfinal = ft_strfinal(str);
	str = ft_strcop(str);
	if (!strfinal)
		return (NULL);
	return (strfinal);
}
