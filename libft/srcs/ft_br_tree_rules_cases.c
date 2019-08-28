/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_tree_rules_cases.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:15:43 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 17:03:15 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_right_right(t_tree *elem, t_tree **root)
{
	t_tree	*parent;
	t_tree	*grand_parent;

	parent = elem->parent;
	grand_parent = elem->parent->parent;
	ft_tree_left_rotate(elem->parent->parent, root);
	ft_br_tree_color_swap(parent, grand_parent);
}

static void	ft_right_left(t_tree *elem, t_tree **root)
{
	ft_tree_right_rotate(elem->parent, root);
	ft_right_right(elem->right, root);
}

static void	ft_left_left(t_tree *elem, t_tree **root)
{
	t_tree	*parent;
	t_tree	*grand_parent;

	parent = elem->parent;
	grand_parent = elem->parent->parent;
	ft_tree_right_rotate(elem->parent->parent, root);
	ft_br_tree_color_swap(parent, grand_parent);
}

static void	ft_left_right(t_tree *elem, t_tree **root)
{
	ft_tree_left_rotate(elem->parent, root);
	ft_left_left(elem->left, root);
}

void		ft_four_cases(t_tree *elem, t_tree **root)
{
	if (elem->parent == elem->parent->parent->right)
	{
		if (elem == elem->parent->right)
			ft_right_right(elem, root);
		else
			ft_right_left(elem, root);
	}
	else
	{
		if (elem == elem->parent->left)
			ft_left_left(elem, root);
		else
			ft_left_right(elem, root);
	}
}
