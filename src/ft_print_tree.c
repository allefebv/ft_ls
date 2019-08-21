/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:52:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/20 15:26:42 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s:\n", (char*)((t_entry*)(content))->path);
}

void	ft_print_line_cr(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s\n", (char*)((t_entry*)(content))->name);
}

void	ft_print_errors(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("ls: %s: %s\n", (char*)((t_entry*)(content))->path,
		(char*)((t_entry*)(content))->error);
}
