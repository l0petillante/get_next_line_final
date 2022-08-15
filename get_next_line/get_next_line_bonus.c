/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:28 by lhmissi           #+#    #+#             */
/*   Updated: 2022/08/14 15:39:40 by lhmissi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_str(int fd, char *str, char *buffer)
{
	int	len;

	len = 0;
	if (!ft_non(str))
		len = read(fd, buffer, BUFFER_SIZE);
	while (!ft_non(str) && len != 0)
	{
		if (len == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len] = 0;
		str = ft_strjoin(str, buffer);
		if (ft_non(str))
			break ;
		if (!str)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*strfinal;
	char		*buffer;

	strfinal = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	str[fd] = ft_str(fd, str[fd], buffer);
	if (!str[fd])
		return (NULL);
	strfinal = ft_strfinal(str[fd]);
	str[fd] = ft_strcop(str[fd], ft_strlen(strfinal));
	if (!strfinal)
		return (NULL);
	return (strfinal);
}
