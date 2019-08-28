/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:36:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 19:29:54 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_br_tree_color	ft_color_of_node(t_tree *elem)
{
	t_br_tree_color color;

	return (color = (elem == NULL) ? black : elem->color);
}

void			ft_br_tree_color_swap(t_tree *elem1, t_tree *elem2)
{
	t_br_tree_color tmp_color;

	tmp_color = elem1->color;
	elem1->color = elem2->color;
	elem2->color = tmp_color;
}

void			ft_br_tree_recolor(t_tree *elem, t_tree *uncle)
{
	uncle->color = black;
	elem->parent->color = black;
	uncle->parent->color = red;
}

t_tree			*ft_tree_grandparent(t_tree *elem)
{
	if (!elem || !elem->parent)
		return (NULL);
	return (elem->parent->parent);
}

t_tree			*ft_tree_uncle(t_tree *elem)
{
	t_tree	*grandparent;

	if (!elem || !(grandparent = ft_tree_grandparent(elem)))
		return (NULL);
	if (elem->parent == grandparent->right)
		return (grandparent->left);
	else
		return (grandparent->right);
}
