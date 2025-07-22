#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stack;
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;    
    stack = ft_read(fd, BUFFER_SIZE, stack);
    if(stack == NULL)
        return(NULL);
    line = malloc((i + 2) * sizeof(char));  // '\n' dahil + '\0' için +1
    if (!line)
        return (NULL);
    while(stack[i] != '\0')
    {
        if(stack[i] == '\n')
        {
            while(j < i)
            {
                line[j] = stack[j];
                j++;
            }
        }
        else
            line = stack;
       i++;
    }
    return (line);
}
/*
stack: fd'den okuduğum işlenmemiş verinin tutulduğu yer.
get_next_lien, stack üzzeirnden veriyi satır satır alır, aldığı veriyi stackten ayırır. Gerisini saklar.


    */