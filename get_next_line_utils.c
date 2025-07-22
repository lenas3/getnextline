#include "get_next_line.h"

char	*ft_join(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*concat;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

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

char	*ft_dupe(char *str)
{
	char	*dupe;
	size_t	i;

	i = 0;
	dupe = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dupe)
		return (NULL);
	while (str[i])
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
size_t	ft_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}