/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 16:31:07 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_files(t_trees_management *trees, t_tree *dir,
				t_tree *file_tree)
{
	if (trees->count_dirs != 1 || trees->count_errors || trees->count_files)
		ft_printf("%s:\n", ((t_entry*)dir->content)->path);
	ft_printf("%s:\n", ((t_entry*)dir->content)->path);
	ft_tree_inorder_print(file_tree, trees->fptr_print);
	closedir(((t_entry*)(dir->content))->stream);
	ft_printf("\n");
}

static int	ft_dir_read(t_trees_management *trees, t_options *options, t_tree *dir)
{
	t_tree			**file_tree;
	t_tree			**subdir_tree;
	t_entry			*file_entry;
	struct dirent	*file;

	file_tree = (t_tree**)malloc(sizeof(t_tree*));
	*file_tree = NULL;
	subdir_tree = (t_tree**)malloc(sizeof(t_tree*));
	*subdir_tree = NULL;
	file_entry = NULL;
	if (!((t_entry*)dir->content)->stream)
	{
		ft_print_errors(dir->content);
		return (1);
	}
	while ((file = readdir(((t_entry*)dir->content)->stream)))
	{
		if ((!options->a && file->d_name[0] == '.'))
			continue ;
		if (!(file_entry = (t_entry*)malloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error));
		file_entry->path = ft_strjoin(((t_entry*)dir->content)->path,
			file->d_name);
		file_entry->name = ft_strdup(file->d_name);
		trees->fptr_stat(file_entry->path, &file_entry->info);
		ft_treeadd(file_tree, ft_treenew_ptr(file_entry), trees->fptr_sort);
		if (options->r_cap && S_ISDIR(file_entry->info.st_mode))
		{
			ft_check_dir_end(&file_entry->path);
			if (!(file_entry->stream = opendir(file_entry->path)))
				file_entry->error = strerror(errno);
			ft_treeadd(subdir_tree,
				ft_treenew_ptr(file_entry), trees->fptr_sort);
		}
	}
	ft_print_files(trees, dir, *file_tree);
	if (options->r_cap && *subdir_tree)
		ft_args_dir_management(trees, options, *subdir_tree);
	return (1);
}

int		ft_args_dir_management(t_trees_management *trees, t_options *options,
		t_tree *dir)
{
	if (!dir)
		return (1);
	ft_args_dir_management(trees, options, dir->left);
	ft_dir_read(trees, options, dir);
	ft_args_dir_management(trees, options, dir->right);
	return (1);
}
