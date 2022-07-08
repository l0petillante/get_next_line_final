#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strjoin("", s2));
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

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

int	main()
{
	static char *s1 = NULL;
	char *s3 = NULL;

	char *s2 = "122";
	s1 = ft_strjoin(s1, s2);
	printf("strjoin :%s\n", s1);

	s2 = "2\n65";
	s1 = ft_strjoin(s1, s2);
	printf("strjoin2 :%s\n", s1);

	s3 = ft_strfinal(s1);
	printf("str final :%s\n", s3);

	s1 = ft_strcop(s1, 4, ft_strlen(s3));
	printf("s1 reduit :%s\n", s1);

	return (1);
}