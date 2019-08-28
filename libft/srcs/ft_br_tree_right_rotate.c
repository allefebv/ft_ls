/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_tree_right_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:22:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 12:36:05 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_right_rotate(t_tree *start_top, t_tree **root)
{
	t_tree	*start_bot;

	start_bot = start_top->left;
	start_top->left = start_bot->right;
	if (start_bot->right)
		start_bot->right->parent = start_top;
	start_bot->parent = start_top->parent;
	if (!start_top->parent)
		*root = start_bot;
	else if (start_top->parent->left == start_top)
		start_top->parent->left = start_bot;
	else if (start_top->parent->right == start_top)
		start_top->parent->right = start_bot;
	start_bot->right = start_top;
	start_top->parent = start_bot;
}
