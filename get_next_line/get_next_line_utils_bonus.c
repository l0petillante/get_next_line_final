/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:21 by lhmissi           #+#    #+#             */
/*   Updated: 2022/08/13 18:08:25 by lhmissi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strcop(char *str, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = len;
	j = 0;
	if (!str || len == 0)
		return (NULL);
	if (ft_strlen(str) == i)
	{
		free (str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
	{
		free (res);
		return (NULL);
	}
	while (res && str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}
