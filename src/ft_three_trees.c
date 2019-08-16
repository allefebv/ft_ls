/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_trees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:43:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 15:16:48 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_error_tree(t_entry *entry, t_trees_management *trees)
{
	entry->error = strerror(errno);
	ft_treeadd(trees->errors, ft_treenew_ptr(entry), ft_name_sort);
	(trees->count_errors)++;
}

static void	ft_file_tree(t_entry *entry, t_trees_management *trees)
{
	ft_treeadd(trees->files, ft_treenew_ptr(entry), trees->fptr_sort);
	(trees->count_files)++;
}

static void	ft_dir_tree(t_entry *entry, t_trees_management *trees)
{
	entry->stream = opendir(entry->path);
	ft_check_dir_end(&entry->path);
	ft_treeadd(trees->dirs, ft_treenew_ptr(entry), trees->fptr_sort);
	(trees->count_dirs)++;
}

static int	ft_opr(t_list *opr, t_trees_management *trees, t_entry *entry)
{
	while (opr)
	{
		if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error));
		entry->path = (char*)opr->content;
		if (trees->fptr_stat(entry->path, &entry->info))
			ft_error_tree(entry, trees);
		else
		{
			if (S_ISDIR(entry->info.st_mode))
				ft_dir_tree(entry, trees);
			else
				ft_file_tree(entry, trees);
		}
		opr = opr->next;
	}
	return (1);
}

int			ft_three_trees(t_list *opr, t_trees_management *trees)
{
	t_entry	*entry;

	entry = NULL;
	if (opr)
		ft_opr(opr, trees, entry);
	else
	{
		if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error));
		entry->path = ft_strdup(".");
		trees->fptr_stat(entry->path, &entry->info);
		ft_dir_tree(entry, trees);
	}
	if (trees->count_errors)
		ft_tree_inorder_print(*trees->errors, ft_print_errors);
	if (trees->count_files)
	{
		ft_tree_inorder_print(*trees->files, ft_print_path_space);
		ft_printf("\n\n");
	}
	return (1);
}
