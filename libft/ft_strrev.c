/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:21:53 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 14:14:26 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	start;
	size_t	end;
	char	tmp;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		tmp = s[end];
		s[end] = s[start];
		s[start] = tmp;
		start++;
		end--;
	}
	return (s);
}
