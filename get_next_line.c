/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:45:26 by asay              #+#    #+#             */
/*   Updated: 2025/07/22 15:45:26 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stack;
    char *line;
    int len_line;
    int i;

    stack = malloc(??? * sizeof(char)); ---> ERROR
    if(!stack)
        return(NULL);
    write(1, "stack\n", 6);
    stack = ft_read(fd, BUFFER_SIZE, stack);
    
    line = ft_dupe(stack, '\n');  
    stack = ft_dupe(ft_newstack(stack), '\0');
    return (line);
}
