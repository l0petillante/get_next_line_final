#include "get_next_line.h"
// possibilite de reprendre strchr aussi
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

// gerer fin du fchier ou sil ny a plus rien a lire
char	*get_next_line(int fd)
{
	static char	*str;
	char		*strfinal;
	char		*buffer;
	size_t		len;

	strfinal = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	len = 1;
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (ft_non(str) == 0 && len != 0)
	{
		len += read(fd, buffer, BUFFER_SIZE);
		if ((int)len == -1 || !buffer)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	strfinal = ft_strfinal(str);
	str = ft_strcop(str);
	return (strfinal);
}
