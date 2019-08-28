/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_tree_left_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:22:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 12:59:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_left_rotate(t_tree *start_top, t_tree **root)
{
	t_tree	*start_bot;

	start_bot = start_top->right;
	start_top->right = start_bot->left;
	if (start_bot->left)
		start_bot->left->parent = start_top;
	start_bot->parent = start_top->parent;
	if (!start_top->parent)
		*root = start_bot;
	else if (start_top->parent->right == start_top)
		start_top->parent->right = start_bot;
	else if (start_top->parent->left == start_top)
		start_top->parent->left = start_bot;
	start_bot->left = start_top;
	start_top->parent = start_bot;
}
