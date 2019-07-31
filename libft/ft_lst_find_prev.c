/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find_prev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:46:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/18 16:27:53 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find_prev(t_list *lst, t_list *elem)
{
	if (lst == NULL || elem == NULL || elem == lst)
		return (NULL);
	while (lst->next != elem)
		lst = lst->next;
	return (lst);
}
