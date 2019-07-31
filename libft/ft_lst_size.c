/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:34:40 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:46:45 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *start)
{
	int	i;

	if (start == NULL)
		return (0);
	i = 1;
	while (start->next != NULL)
	{
		start = start->next;
		i++;
	}
	return (i);
}
