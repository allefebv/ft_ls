/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:44:24 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 20:52:49 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd(t_list **alst, t_list *elem)
{
	if (elem == NULL || alst == NULL)
		return (0);
	elem->next = *alst;
	*alst = elem;
	return (1);
}
