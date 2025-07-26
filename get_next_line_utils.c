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

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return ((size_t)NULL);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*concat;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	concat = malloc((ft_len(s1) + ft_len(s2) + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		concat[i++] = s2[j++];
	concat[i] = '\0';
	free(s1);
	return (concat);
}

char	*ft_strdup(char *str)
{
	char	*dupe;
	size_t	i;

	i = 0;
	if(!str)
		return (NULL);
	dupe = malloc((ft_len(str) + 1) * sizeof(char));
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

char	*ft_strchr(const char *str, int a)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)a)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)a == '\0')
		return ((char *)&str[i]);
	return (NULL);
}