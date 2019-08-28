/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_treeadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:43:28 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 21:04:29 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_rules(t_tree **root, t_tree *elem)
{
	t_tree	*uncle;

	uncle = ft_tree_uncle(elem);
	if (elem->parent == NULL)
		elem->color = black;
	else if (elem->parent->color == black)
		return ;
	else if (uncle && uncle->color == red)
	{
		ft_br_tree_recolor(elem, uncle);
		ft_check_rules(root, elem->parent->parent);
	}
	else
		ft_four_cases(elem, root);
}

int		ft_br_treeadd(t_tree **root, t_tree *elem, int (*ft_comp)(void*, void*))
{
	if (!(ft_treeadd(root, elem, ft_comp)))
		return (0);
	elem->color = red;
	ft_check_rules(root, elem);
	return (1);
}
