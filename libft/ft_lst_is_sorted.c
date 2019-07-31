/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:07:43 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/18 13:18:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_is_sorted(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL && *(int*)lst->content < *(int*)lst->next->content)
		lst = lst->next;
	if (lst->next == NULL)
		return (1);
	return (0);
}
