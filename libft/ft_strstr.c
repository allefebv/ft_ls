/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:36:03 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:57:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
