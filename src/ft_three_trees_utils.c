/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_trees_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:23:57 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 15:08:26 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_error_tree(t_ls *ls, t_entry *entry, t_trees_management *trees)
{
	entry->error = strerror(errno);
	if (!(ft_br_treeadd(trees->errors, ft_treenew_ptr(entry), ft_name_sort)))
		return (ft_error(e_malloc_error, NULL));
	ls->print_dir_name_flag = 2;
	ls->is_arg_error_tree = 1;
	return (1);
}

int	ft_file_tree(t_ls *ls, t_entry *entry, t_trees_management *trees,
				t_lengths *lengths)
{
	if (!(ft_long_format(ls, entry, lengths)))
		return (ft_error(e_no_print, NULL));
	if (!(ft_br_treeadd(trees->files, ft_treenew_ptr(entry), ls->fptr_sort)))
		return (ft_error(e_malloc_error, NULL));
	ls->print_dir_name_flag = 2;
	ls->is_arg_files_tree = 1;
	return (1);
}

int	ft_dir_tree(t_ls *ls, t_entry *entry, t_trees_management *trees)
{
	if (!(ft_br_treeadd(trees->dirs, ft_treenew_ptr(entry), ls->fptr_sort)))
		return (ft_error(e_malloc_error, NULL));
	(ls->print_dir_name_flag)++;
	return (1);
}
