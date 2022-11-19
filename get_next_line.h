#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


char * get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
#endif