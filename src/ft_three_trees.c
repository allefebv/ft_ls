/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_trees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:43:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 21:45:48 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_error_tree(t_ls *ls, t_entry *entry, t_trees_management *trees)
{
	entry->error = strerror(errno);
	if (!(ft_br_treeadd(trees->errors, ft_treenew_ptr(entry), ft_name_sort)))
		return (ft_error(e_malloc_error));
	ls->print_dir_name_flag = 2;
	ls->is_arg_error_tree = 1;
	return (1);
}

static int	ft_file_tree(t_ls *ls, t_entry *entry, t_trees_management *trees,
				t_lengths *lengths)
{
	if (!(ft_long_format(ls, entry, lengths)))
		return (ft_error(e_no_print));
	if (!(ft_br_treeadd(trees->files, ft_treenew_ptr(entry), ls->fptr_sort)))
		return (ft_error(e_malloc_error));
	ls->print_dir_name_flag = 2;
	ls->is_arg_files_tree = 1;
	return (1);
}

static int	ft_dir_tree(t_ls *ls, t_entry *entry, t_trees_management *trees)
{
	if (!(ft_br_treeadd(trees->dirs, ft_treenew_ptr(entry), ls->fptr_sort)))
		return (ft_error(e_malloc_error));
	(ls->print_dir_name_flag)++;
	return (1);
}

static int	ft_entry_init(t_entry **entry, t_list *opr)
{
	if (!(*entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
		return (ft_error(e_malloc_error));
	(*entry)->path = (char*)opr->content;
	if (!((*entry)->name = ft_strdup((*entry)->path)))
		return (ft_error(e_malloc_error));
	return (1);
}

static int	ft_opr(t_ls *ls, t_list *opr, t_trees_management *trees,
				t_lengths *lengths)
{
	t_entry	*entry;

	entry = NULL;
	while (opr)
	{
		if (!(ft_entry_init(&entry, opr)))
			return (ft_error(e_no_print));
		if (lstat(entry->path, &entry->info))
		{
			if (!(ft_error_tree(ls, entry, trees)))
				return (ft_error(e_no_print));
		}
		else
		{
			if (S_ISDIR(entry->info.st_mode))
			{
				if (!(ft_dir_tree(ls, entry, trees)))
					return (ft_error(e_no_print));
			}
			else if (!(ft_file_tree(ls, entry, trees, lengths)))
				return (ft_error(e_no_print));
		}
		opr = opr->next;
	}
	return (1);
}

int			ft_three_trees(t_ls *ls, t_list *opr, t_trees_management *trees)
{
	t_entry		*entry;
	t_lengths	lengths;

	ft_bzero(&lengths, sizeof(t_lengths));
	entry = NULL;
	if (opr)
	{
		if (!(ft_opr(ls, opr, trees, &lengths)))
			return (ft_error(e_no_print));
	}
	else
	{
		if (!(entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error));
		if (!(entry->path = ft_strdup(".")))
			return (ft_error(e_malloc_error));
		lstat(entry->path, &entry->info);
		if (!(ft_dir_tree(ls, entry, trees)))
			return (ft_error(e_no_print));
	}
	if (ls->is_arg_error_tree)
		ft_tree_inorder_print(*trees->errors, NULL, ft_print_errors);
	if (ls->is_arg_files_tree)
		ft_tree_inorder_print(*trees->files, &lengths, ls->fptr_print);
	return (1);
}
