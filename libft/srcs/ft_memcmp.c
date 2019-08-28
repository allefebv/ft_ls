/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:12:48 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 12:27:24 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*s1_2;
	unsigned char	*s2_2;
	unsigned int	i;

	s1_2 = (unsigned char*)s1;
	s2_2 = (unsigned char*)s2;
	i = 0;
	while (i < len && s1_2[i] == s2_2[i])
		i++;
	if (i == len)
		return (0);
	return (s1_2[i] - s2_2[i]);
}
