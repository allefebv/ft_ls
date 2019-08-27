/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_trees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:43:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 19:28:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_entry_init(t_entry **entry, t_list *opr)
{
	if (!(*entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
		return (ft_error(e_malloc_error, NULL));
	ft_bzero(*entry, sizeof(t_entry));
	(*entry)->path = ft_strdup((char*)opr->content);
	if (!((*entry)->name = ft_strdup((*entry)->path)))
		return (ft_error(e_malloc_error, NULL));
	return (1);
}

static int	ft_opr_file_dir(t_entry *entry, t_ls *ls, t_trees_management *trees,
				t_lengths *lengths)
{
	entry->type = ft_file_mode((entry->info.st_mode));
	if (S_ISDIR(entry->info.st_mode))
	{
		if (!(ft_dir_tree(ls, entry, trees)))
			return (ft_error(e_no_print, NULL));
	}
	else if (!(ft_file_tree(ls, entry, trees, lengths)))
		return (ft_error(e_no_print, NULL));
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
			return (ft_error(e_no_print, NULL));
		if (ls->fptr_stat(entry->path, &entry->info))
		{
			if (!(ft_error_tree(ls, entry, trees)))
				return (ft_error(e_no_print, NULL));
		}
		else if (!ft_opr_file_dir(entry, ls, trees, lengths))
			return (ft_error(e_no_print, NULL));
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
			return (ft_error(e_no_print, NULL));
	}
	else
	{
		if (!(entry = (t_entry*)ft_memalloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error, NULL));
		if (!(entry->path = ft_strdup(".")))
			return (ft_error(e_malloc_error, NULL));
		lstat(entry->path, &entry->info);
		if (!(ft_dir_tree(ls, entry, trees)))
			return (ft_error(e_no_print, NULL));
	}
	if (ls->is_arg_error_tree)
		ft_tree_inorder_print(*trees->errors, NULL, ft_print_errors);
	if (ls->is_arg_files_tree && !(ls->first = 0))
		ft_tree_inorder_print(*trees->files, &lengths, ls->fptr_print);
	return (1);
}
