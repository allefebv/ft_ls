/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:28:12 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:14:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		len;
	char		*new;

	if (!(s))
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (i != ft_strlen(s))
	{
		if (!(new = ft_strsub(s, i, (len - i + 1))))
			return (NULL);
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(new) * ft_strlen(s))))
			return (NULL);
		ft_bzero(new, ft_strlen(s));
	}
	return (new);
}
