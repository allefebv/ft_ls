/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:18:44 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 20:38:43 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_sort(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;
	int		posmin;

	i = 0;
	j = 0;
	while (i < len)
	{
		posmin = i;
		j = i + 1;
		while (j < len)
		{
			if (tab[j] < tab[posmin])
				posmin = j;
			j++;
		}
		tmp = tab[posmin];
		tab[posmin] = tab[i];
		tab[i] = tmp;
		i++;
	}
}
