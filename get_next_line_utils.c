/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:45:33 by asay              #+#    #+#             */
/*   Updated: 2025/07/22 15:45:33 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	concat = (char *)malloc((ft_length(s1, '\0') + ft_length(s2, '\0')) * sizeof(char));
	if (!concat)
		return (NULL);
	write(1, "ft_join\n", 8);
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

size_t	ft_length(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' || str[i] != c)
		i++;
	return (i);
}
char	*ft_dupe(char *str, char c)
{
	char	*dupe;
	size_t	i;

	i = 0;
	dupe = malloc((ft_length(str, '\0') + 1) * sizeof(char));
	if (!dupe)
		return (NULL);
	write(1, "ft_dupe\n", 8);
	while (str[i] && str[i] != c)
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char *ft_read(int fd, int buff_size, char *stack)  
{
    char *buffer;
	
    buffer = malloc((buff_size + 1) * sizeof(char));
    if(!buffer)
        return (NULL);
	write(1, "ft_read\n", 8);
    size_t bytes;
    bytes = read(fd, buffer, buff_size);
    if(bytes <= 0)
    {
        free(buffer);
        return (stack);
    }
    buffer[bytes] = '\0';
    stack = ft_join(stack, buffer);
    free (buffer); // işim bitti free'liyorum.
    return (stack);
}

char *ft_newstack(char *stack)
{
	int remainlen;
	int linelen;
	int i;
	char *newstack;

	i = 0;
	linelen = ft_length(stack, '\n');
	remainlen = ft_length(stack + linelen + 1, '\0');
	
	newstack = malloc((remainlen + 1) * sizeof(char));
	if(!newstack)
		return (NULL);
	write(1, "ft_newstack", 11);
	while(i < remainlen)
	{
		newstack[i] = stack[linelen + i];
		i++;
	}
	return(newstack);
}
