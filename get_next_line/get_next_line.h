/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: alfeofan <alfeofan@student.42lausanne.ch>     +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/11 18:59:54 by alfeofan       #+#    #+#                */
/*   Updated: 2026/02/11 19:00:04 by alfeofan       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
