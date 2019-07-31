/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:45:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strextend(char *s1, char const *s2)
{
	char	*tmp;

	if (!(s1) || !(s2))
		return (NULL);
	tmp = s1;
	if (!(s1 = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(s1, tmp);
	ft_strcat(s1, s2);
	free(tmp);
	return (s1);
}
