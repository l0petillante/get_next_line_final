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
		{
			free(buffer);
			return (NULL);
		}
		len = read(fd, buffer, BUFFER_SIZE);
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
	{
		free (buffer);
		return (NULL);
	}
	str = ft_str(fd, str, buffer);
	if (!str)
		return (NULL);
	strfinal = ft_strfinal(str);
	str = ft_strcop(str, ft_strlen(strfinal));
	if (!strfinal)
	{
		free(strfinal);
		return (NULL);
	}
	return (strfinal);
}
