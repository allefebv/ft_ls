/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:57:03 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:13:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	while (dst[i] != '\0' && i < len)
		i++;
	while (src[j] != '\0' && (i + 1) < len)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < len)
	{
		dst[i] = '\0';
		return (ft_strlen(src) + dst_len);
	}
	return (ft_strlen(src) + len);
}
