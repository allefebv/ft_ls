/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:22:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 21:02:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_comp return values :
** RETURN NEGATIF si node GAUCHE root
** RETURN 0 ou PLUS si node DROITE root
*/

int		ft_treeadd(t_tree **root, t_tree *node, int (*ft_comp)(void*, void*))
{
	t_tree	*probe;
	t_tree	*future_parent;

	if (node == NULL || root == NULL)
		return (0);
	else if (*root == NULL && (*root = node))
	{
		node->parent = NULL;
		return (1);
	}
	probe = *root;
	while (probe != NULL)
	{
		future_parent = probe;
		if (ft_comp(probe->content, node->content) >= 0)
			probe = probe->right;
		else
			probe = probe->left;
	}
	if (ft_comp(future_parent->content, node->content) >= 0)
		future_parent->right = node;
	else
		future_parent->left = node;
	node->parent = future_parent;
	return (1);
}
