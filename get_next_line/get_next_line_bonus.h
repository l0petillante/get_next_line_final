#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_non(char *str);
char	*ft_str(int fd, char *str, char *buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcop(char *str, size_t len);
char	*ft_strfinal(char *str);

#endif
