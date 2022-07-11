#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strjoin("", s2));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strfinal(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
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

char	*ft_strcop(char *str)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	i++;
	if (!res)
	{
		free (res);
		return (NULL);
	}
	while (str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}
