/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:17:21 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/31 20:01:09 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *))
{
	t_list	*save_next;

	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		save_next = lst->next;
		f(lst);
		lst = save_next;
	}
}
