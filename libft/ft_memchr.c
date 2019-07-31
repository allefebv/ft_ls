/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:44:35 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:31:31 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*s_2;
	size_t			i;

	s_2 = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (s_2[i] == (unsigned char)c)
			return (s_2 + (unsigned char)i);
		i++;
	}
	return (NULL);
}
