/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:28 by reldahli          #+#    #+#             */
/*   Updated: 2023/12/05 12:37:15 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	temp_c;

	i = 0;
	temp_c = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == temp_c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == temp_c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
