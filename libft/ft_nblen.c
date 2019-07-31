/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:08:02 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 18:13:17 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_nblen(int n)
{
	size_t			tab_size;
	unsigned int	cpy;

	tab_size = 1;
	cpy = n;
	if (n < 0)
	{
		tab_size++;
		cpy = n * -1;
	}
	while (cpy >= 10)
	{
		tab_size++;
		cpy = cpy / 10;
	}
	return (tab_size);
}
