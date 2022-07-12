#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main	(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	// s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	// printf("%lu\n", read(fd, s, BUFFER_SIZE));
	s = get_next_line(fd);
	while(s)
	{
		printf("LIGNE FINAL :%s", s);
		free (s);
		s = get_next_line(fd);
	}
	return (0);
}	
