/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:00:34 by reldahli          #+#    #+#             */
/*   Updated: 2023/12/05 13:02:04 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			temp_c;
	char			*res;

	i = 0;
	temp_c = (char)c;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == temp_c)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		res = (char *)&s[i];
	}
	return (res);
}
