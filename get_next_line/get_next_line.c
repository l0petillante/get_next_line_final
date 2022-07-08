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

char	*get_next_line(int fd)
{
	static char	*str;
	char	*strfinal;
	char	*buffer;
	size_t	len;

	str = NULL;
	strfinal = NULL;
	len = 0;
	if (!buffer)
		return (NULL);
	while (ft_non(str) == 0 && len%BUFFER_SIZE == 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		len += read(fd, buffer, BUFFER_SIZE);
		printf("buffer : %s et str :%s\n", buffer, str);
		str = ft_strjoin(str, buffer);
		free(buffer);
	}
	// gérer la fin du fichier 
	if (len % BUFFER_SIZE != 0)
	{

	}
	strfinal = ft_strfinal(str);
	str = ft_strcop(str, len, ft_strlen(strfinal));
	return (strfinal);	
}
