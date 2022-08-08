/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:21 by lhmissi           #+#    #+#             */
/*   Updated: 2022/08/08 19:18:18 by lhmissi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	size;
	int		i;
	char	*res;

	size = ft_strlen(s);
	i = 0;
	if (!s || size == 0)
		return (NULL);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
	{
		free(res);
		return (NULL);		
	}
	else
	{
		while (size > 0)
		{
			res[i] = s[i];
			i++;
			size --;
		}
		res[i] = '\0';
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 && s1)
		return (s1);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	re = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!re || ((ft_strlen(s1) + ft_strlen(s2)) == 0))
	{
		free(re);
		return (NULL);	
	}
	while (s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		re[i++] = s2[j++];
	}
	re[i] = '\0';
	free(s1);
	return (re);
}

char	*ft_strfinal(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	while (i >= 0)
	{
		res[j] = str[j];
		j++;
		i--;
	}
	res[j] = '\0';
	return (res);
}

// revoir i et j de cette fonction 
char	*ft_strcop(char *str)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] && str[i] != '\n')
		i++;
	j = i;
	i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	// i++;
	if (!res || ft_strlen(str) <= i)
	{
		free (res);
		return (NULL);
	}
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:28 by lhmissi           #+#    #+#             */
/*   Updated: 2022/08/08 18:51:17 by lhmissi          ###   ########.fr       */
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
	// if (!str || len == 0)
	// {
	// 	free (buffer);
	// 	return (NULL);
	// }
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
	{
		free (buffer);
		return (NULL);
	}
	str = ft_str(fd, str, buffer);
	if (!str)
		return (NULL);
	strfinal = ft_strfinal(str);
	str = ft_strcop(str);
	if (!strfinal)
		return (NULL);
	return (strfinal);
}

