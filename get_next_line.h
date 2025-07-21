#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>

char *ft_read(int fd, int buff_size, char *stack);
char	*ft_join(char const *s1, char const *s2);

#endif 