/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_inlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:25:26 by allefebv          #+#    #+#             */
/*   Updated: 2019/03/05 14:45:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_is_inlist(t_list *list, t_list *elem)
{
	if (list == NULL)
		return (0);
	while (list->next != NULL && list != elem)
		list = list->next;
	if (list == elem)
		return (1);
	else
		return (0);
}
