/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:45:02 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:32:49 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*s_2;
	size_t			i;

	s_2 = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		s_2[i] = c;
		i++;
	}
	return (s);
}
