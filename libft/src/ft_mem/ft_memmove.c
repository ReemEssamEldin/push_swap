/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:48:10 by reldahli          #+#    #+#             */
/*   Updated: 2023/12/12 12:17:57 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_src;
	char	*temp_dst;
	size_t	i;

	temp_src = (char *)src;
	temp_dst = (char *)dst;
	if (temp_src == NULL || temp_dst == NULL)
		return (NULL);
	if (temp_dst < temp_src || temp_dst >= (temp_src + len))
	{
		while (len--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		i = len - 1;
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i--;
		}
	}
	return (dst);
}
