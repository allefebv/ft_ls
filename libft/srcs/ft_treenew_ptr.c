/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:46:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 13:38:55 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_tree	*ft_treenew_ptr(void *content)
{
	t_tree	*new;

	if (!(new = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
		new->content = content;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	return (new);
}
