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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strjoin("", s2));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	printf("avant :%s\n",s2);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	printf("apres :%s\n",s2);
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

// fonction qui copie une str dans un str final jusqu'au premier \n

char	*ft_strfinal(char *str)
{
	char	*strfinal;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	strfinal = malloc(sizeof(char) * i + 1);
	if (!strfinal)
	{
		free(strfinal);
		return (NULL);
	}
	while (i >= 0)
	{
		strfinal[j] = str[j];
		j++;
		i--;
	}
	strfinal[i] = '\0';
	return (strfinal);
}

// fonction qui copie str à partir du premier \n
char	*ft_strcop(char *str, size_t len, size_t slen)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = slen;
	j = 0;
	res = malloc(sizeof(char) * (len - slen + 1));
	if (!res)
		return (NULL);
	while (j < len)
	{
		res[j] = str[i];
		j++;
		i++;
	}
	return (res);
}
