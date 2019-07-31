/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:20:09 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 13:06:59 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_2;
	unsigned char	*src_2;

	dst_2 = (unsigned char*)dst;
	src_2 = (unsigned char*)src;
	if (dst_2 > src_2)
		while (len)
		{
			dst_2[len - 1] = src_2[len - 1];
			len--;
		}
	else
		ft_memcpy(dst_2, src_2, len);
	return (dst);
}
