/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:00:20 by reldahli          #+#    #+#             */
/*   Updated: 2023/12/05 12:58:31 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	size_t	i;

	s2_len = ft_strlen(s2);
	i = 0;
	if (!*s2)
	{
		return ((char *)s1);
	}
	if (ft_strlen(s1) < s2_len || n < s2_len)
	{
		return (NULL);
	}
	while (i <= n - s2_len)
	{
		if (ft_strncmp(s1 + i, s2, s2_len) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
