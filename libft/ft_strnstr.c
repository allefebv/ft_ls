/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:34:56 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 15:48:12 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		while (s[i] == needle[j] && needle[j] != '\0'
			&& s[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)s + i - j);
		if (j == 0)
			i++;
		else
			i = i - j + 1;
	}
	return (NULL);
}
