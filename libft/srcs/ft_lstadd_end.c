/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:26:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 20:53:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_end(t_list **alst, t_list *elem)
{
	t_list *end;

	if (elem == NULL || alst == NULL)
		return (0);
	if (*alst == NULL)
	{
		if (!(ft_lstadd(alst, elem)))
			return (0);
	}
	else
	{
		end = *alst;
		while (end->next != NULL)
			end = end->next;
		end->next = elem;
		elem->next = NULL;
	}
	return (1);
}
