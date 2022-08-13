/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhmissi <lhmissi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:02:31 by lhmissi           #+#    #+#             */
/*   Updated: 2022/08/13 16:42:49 by lhmissi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_non(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_str(int fd, char *str, char *buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcop(char *str,size_t len);
char	*ft_strfinal(char *str);

#endif
