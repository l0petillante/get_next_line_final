#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

// gerer la fin du fichier;

int	main	(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	// s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	// printf("%lu\n", read(fd, s, BUFFER_SIZE));
	s = get_next_line(fd);
	printf("%s\n", s);
	while(s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	return (0);
}
