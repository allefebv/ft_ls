/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/14 20:12:38 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_dir_management(t_trees_management *trees, t_options *options, t_tree *dir)
{
	t_tree			**file_tree;
	t_entry			*file_entry;
	struct dirent	*file;

	file_tree = (t_tree**)malloc(sizeof(t_tree*));
	*file_tree = NULL;

	if (!dir)
		return (1);
	ft_dir_management(trees, options, dir->left);
	while ((file = readdir(((t_entry*)dir->content)->stream)))
	{
		if ((!options->a && file->d_name[0] != '.') || options->a)
		{
			if (!(file_entry = (t_entry*)malloc(sizeof(t_entry))))
				return (ft_error(e_malloc_error));
			file_entry->path = ft_strjoin(((t_entry*)dir->content)->path,
				file->d_name);
			file_entry->name = ft_strdup(file->d_name);
			trees->fptr_stat(file_entry->path, &file_entry->info);
			ft_treeadd(file_tree, ft_treenew_ptr(file_entry), trees->fptr_sort);
		}
	}
	if (trees->count_dirs != 1 || trees->count_errors || trees->count_files)
		ft_printf("%s:\n", ((t_entry*)dir->content)->path);
	ft_tree_inorder_print(*file_tree, trees->fptr_print);
	ft_dir_management(trees, options, dir->right);
	return (1);
}
