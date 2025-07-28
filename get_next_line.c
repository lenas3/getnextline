/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:45:00 by asay              #+#    #+#             */
/*   Updated: 2025/07/25 16:45:00 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, int buff_size, char *stack)
{
	char	*buffer;
	int		bytes;

	if (buff_size < 1)
		return (NULL);
	buffer = malloc((buff_size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, buff_size);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stack = ft_join(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (stack);
}

char	*ft_newstack(char *stack)
{
	int		fullen;
	int		i;
	char	*newstack;
	char	*lineptr;

	if (!stack)
		return (NULL);
	lineptr = ft_strchr(stack, '\n');
	if (!lineptr)
		return (free(stack), NULL);
	fullen = ft_len(stack) - (lineptr - stack + 1);
	newstack = malloc((fullen + 1) * sizeof(char));
	if (!newstack)
		return (NULL);
	i = 0;
	while (stack[(lineptr - stack) + 1 + i])
	{
		newstack[i] = stack[(lineptr - stack) + 1 + i];
		i++;
	}
	newstack[i] = '\0';
	free (stack);
	return (newstack);
}

char	*ft_getline(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stack || !stack[0])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = ft_read(fd, BUFFER_SIZE, stack);
	if (!stack)
		return (NULL);
	line = ft_getline(stack);
	stack = ft_newstack(stack);
	return (line);
}
