/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:38:03 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 12:20:41 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*dst_2;
	unsigned char	*src_2;
	unsigned int	i;

	dst_2 = (unsigned char*)dst;
	src_2 = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		dst_2[i] = src_2[i];
		if (src_2[i] == (unsigned char)c)
			return (dst_2 + i + 1);
		i++;
	}
	return (NULL);
}
