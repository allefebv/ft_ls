/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:43:16 by allefebv          #+#    #+#             */
/*   Updated: 2018/11/15 12:40:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t len)
{
	void	*ptr;

	if (!(ptr = malloc(len)))
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
