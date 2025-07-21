#include "get_next_line.h"

char *ft_read(int fd, int buff_size, char *stack)  
{
    char *buffer;
    buffer = malloc((buff_size + 1) * sizeof(char));
    if(!buffer)
        return (NULL);

    size_t bytes;
    bytes = read(fd, buffer, buff_size);
    if(bytes <= 0)
    {
        free(buffer);
        return (stack);
    }
    buffer[bytes] = '\0';
//yukarıda buffer[bytes] yapmamızın sebebi, read her zaman buff_size kadar okumayabilir.
//eğer daha az okursa ve biz buffer[buff_size] yapmış olsaydım okumadığım bi bellek alanını sonlandırmaya çalışıyor olurdum, saçma.

    stack = ft_join(stack, buffer);
    free (buffer); // işim bitti free'liyorum.
    return (stack);
}