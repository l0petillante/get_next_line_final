#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

// static char *str = NULL;
// while  (ya pas de /n dans str)
// 	buffer = read(fd)
// 	strjoin(str, buffer 1)
// 	free(buffer) //free
// "xxxxxx\nxx\nx\nxxx\nxx" str
// il faut que tu envoie "xxxxxx\n" la premiere
// '\n' la deuxieme etc..
// str_final= copie tout str jusquau premier \n inclue
// str = devient "xx\nx\nxxx\nxx" //free
// 3 fonctions:
// une qui strjoin les buffer jusqua avoir un \n
// une qui prepapre la str a renvoyer (malloc et copie jusqua 1er /n)
// une qui prepare la str dans le futur (copie tout apres le 1er\n et free la version precedente)
// ger la fin du fichier;
// return(str_final)

int	main	(void)
{
	int		fd;
	char	*str;

	fd= open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	// while(str)
	// {
	// 	printf("%s\n", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// }
	return (0);
}	