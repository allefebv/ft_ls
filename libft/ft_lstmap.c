/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:04:41 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/31 16:12:23 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parcourt la liste lst en appliquant à chaque maillon la fonction f et
**	crée une nouvelle liste “fraiche” avec malloc(3) résultant des applications
**	successives. Si une allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new_elm;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(begin = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	new_elm = begin;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new_elm->next = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		new_elm = new_elm->next;
		lst = lst->next;
	}
	return (begin);
}
