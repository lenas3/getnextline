#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *ft_read(int fd, int buff_size, char *stack);
char    *ft_join(char const *s1, char const *s2);
size_t	ft_length(const char *str);
char	*ft_dupe(char *str);


#endif 