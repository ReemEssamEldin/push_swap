/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:06:10 by reldahli          #+#    #+#             */
/*   Updated: 2024/01/30 13:06:13 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	space;

	space = count * size;
	if (count && (size != (space / count)))
		return (NULL);
	ptr = (void *)malloc(space);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, space);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;
	char			c1;

	s1 = (unsigned char *)s;
	c1 = (char)c;
	while (n--)
	{
		*s1++ = c1;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	temp_c;

	i = 0;
	temp_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == temp_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == temp_c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*s3;
	int		i;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((sizeof(char) * total_len) + 1);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
