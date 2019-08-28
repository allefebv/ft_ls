/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_inorder_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:28:26 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/18 12:03:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_inorder_print(t_tree *root, void *additional_content,
			void (*ft_print)(void*, void*))
{
	if (!root)
		return ;
	ft_tree_inorder_print(root->left, additional_content, ft_print);
	ft_print(root->content, additional_content);
	ft_tree_inorder_print(root->right, additional_content, ft_print);
}
