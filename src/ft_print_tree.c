/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:52:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/14 20:12:42 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(void *content)
{
	ft_printf("%s:\n", (char*)((t_entry*)(content))->path);
}

void	ft_print_line_cr(void *content)
{
	ft_printf("%s\n", (char*)((t_entry*)(content))->name);
}

void	ft_print_line_long(void *content)
{
	(void)content;
}

void	ft_print_path_space(void *content)
{
	ft_printf("%s ", (char*)((t_entry*)(content))->path);
}

void	ft_print_errors(void *content)
{
	ft_printf("ls: %s: %s\n", (char*)((t_entry*)(content))->path,
		(char*)((t_entry*)(content))->error);
}
