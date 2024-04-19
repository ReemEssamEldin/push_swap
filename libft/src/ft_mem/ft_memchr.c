/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:52:31 by reldahli          #+#    #+#             */
/*   Updated: 2023/12/12 10:44:05 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*temp_str;
	unsigned char	temp_c;

	i = 0;
	temp_str = (unsigned char *)str;
	temp_c = (unsigned char)c;
	while (i < size)
	{
		if (temp_str[i] == temp_c)
		{
			return ((void *)&temp_str[i]);
		}
		i++;
	}
	return (NULL);
}
