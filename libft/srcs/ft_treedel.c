/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:25:38 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/26 15:51:42 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_treedel(t_tree **root, void (*del)(void *, size_t))
{
	if (!root || !*root)
		return ;
	if (*root && (*root)->left != NULL)
		ft_treedel(&(*root)->left, del);
	if (*root && (*root)->right != NULL)
		ft_treedel(&(*root)->right, del);
	ft_treedelone(root, del);
	free(*root);
	*root = NULL;
}
