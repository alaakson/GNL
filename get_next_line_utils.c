/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:58:27 by alaakson          #+#    #+#             */
/*   Updated: 2024/05/28 10:14:50 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		d;
	int		s;

	d = 0;
	s = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[s])
	{
		dest[d++] = s1[s++];
	}
	s = 0;
	while (s2[s])
	{
		dest[d++] = s2[s++];
	}
	dest[d] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	length;

	length = ft_strlen(s1);
	dest = ((char *)malloc(length + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			set;

	set = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == set)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == set)
		return ((char *) &s[i]);
	return (NULL);
}
