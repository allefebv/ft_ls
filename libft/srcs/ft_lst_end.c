/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:17:29 by allefebv          #+#    #+#             */
/*   Updated: 2019/02/07 19:11:04 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_end(t_list *start)
{
	t_list	*end;

	end = start;
	if (start == NULL)
		return (NULL);
	while (end->next != NULL)
		end = end->next;
	return (end);
}
