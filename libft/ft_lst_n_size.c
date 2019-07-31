/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_n_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:58:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:46:59 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_n_size(t_list *start, t_list *end)
{
	int	i;

	if (start == NULL)
		return (0);
	i = 1;
	while (start != end && start->next != NULL)
	{
		start = start->next;
		i++;
	}
	return (i);
}
