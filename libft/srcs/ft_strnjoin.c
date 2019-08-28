/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:22:36 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/21 14:17:07 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*new;
	int		i;

	if (!(s1) || !(s2))
		return (NULL);
	if (len < ft_strlen(s2))
		i = ft_strlen(s1) + len;
	else
		i = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(new) * (i + 1))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strncat(new, s2, len);
	return (new);
}
