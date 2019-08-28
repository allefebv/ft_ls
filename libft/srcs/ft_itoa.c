/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:26:55 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/29 14:58:30 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	cpy;

	i = 0;
	cpy = n;
	if (!(str = ft_strnew(ft_nblen(n))))
		return (NULL);
	if (n < 0)
		cpy = n * -1;
	while (cpy >= 10)
	{
		str[i] = cpy % 10 + 48;
		cpy = cpy / 10;
		i++;
	}
	str[i] = cpy + 48;
	if (n < 0)
	{
		i++;
		str[i] = '-';
	}
	str = ft_strrev(str);
	return (str);
}
