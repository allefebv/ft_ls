/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:33:47 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 18:25:43 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*strcpy;

	if (ft_strlen(s) > len)
	{
		if (!(strcpy = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(strcpy, s, len);
	}
	else
	{
		if (!(strcpy = ft_strdup(s)))
			return (NULL);
	}
	return (strcpy);
}
