/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:21:39 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 15:09:54 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_error(t_errors error, void *add)
{
	char	*msg;

	msg = strerror(errno);
	if (error == e_malloc_error)
		ft_printf("ls: %s\n", msg);
	else if (error == e_usage)
	{
		ft_printf("ls: illegal option -- %c\n", *(char*)add);
		ft_printf("usage: ft_ls [Ralrt1] [file ...]\n");
	}
	return (0);
}
