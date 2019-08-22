/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:52:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 21:26:20 by allefebv         ###   ########.fr       */
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

void	ft_print_open_error(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s:\n", (char*)((t_entry*)(content))->path);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd((char*)((t_entry*)(content))->name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char*)((t_entry*)(content))->error, 2);
	ft_putchar_fd('\n', 2);
}

void	ft_print_files(t_ls *ls, t_tree *dir, t_tree *file_tree,
			t_lengths *lengths)
{
	if (ls->print_dir_name_flag < 2)
	{
		ls->print_dir_name_flag = 2;
		ls->first = 0;
	}
	else
	{
		if (!ls->first)
			ft_printf("\n");
		ls->first = 0;
		ft_putstr(((t_entry*)dir->content)->path);
		ft_putstr(":\n");
	}
	if (ls->options.l && file_tree)
		ft_printf("total %d\n", lengths->blocks);
	ft_tree_inorder_print(file_tree, lengths, ls->fptr_print);
	closedir(((t_entry*)(dir->content))->stream);
}
