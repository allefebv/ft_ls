/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/21 15:12:29 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_files(t_ls *ls, t_tree *dir, t_tree *file_tree,
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
	if (ls->options.l)
		ft_printf("total %d\n", lengths->blocks);
	ft_tree_inorder_print(file_tree, lengths, ls->fptr_print);
	closedir(((t_entry*)(dir->content))->stream);
}

static void	ft_dir_read_init(t_tree **file_tree, t_tree **subdir_tree,
				t_entry **file_entry, t_lengths *lengths)
{
	*file_tree = NULL;
	*subdir_tree = NULL;
	*file_entry = NULL;
	ft_bzero(lengths, sizeof(t_lengths));
}

static int	ft_file_entry_init(struct dirent *file,
				t_entry **file_entry, t_tree *dir)
{
	if (!(*file_entry = (t_entry*)malloc(sizeof(t_entry))))
		return (ft_error(e_malloc_error));
	ft_bzero(*file_entry, sizeof(t_entry));
	if (ft_strequ(((t_entry*)dir->content)->path, "/"))
		(*file_entry)->path = ft_strjoin(((t_entry*)dir->content)->path, file->d_name);
	else
	{
		(*file_entry)->path = ft_strjoin(((t_entry*)dir->content)->path, "/");
		(*file_entry)->path = ft_strextend((*file_entry)->path, file->d_name);
	}
	(*file_entry)->name = ft_strdup(file->d_name);
	lstat((*file_entry)->path, &(*file_entry)->info);
	return (1);
}

static int	ft_dir_read(t_ls *ls, t_tree *dir)
{
	t_tree			*file_tree;
	t_tree			*subdir_tree;
	t_entry			*file_entry;
	struct dirent	*file;
	t_lengths		lengths;

	if (!(((t_entry*)dir->content)->stream =
		opendir(((t_entry*)dir->content)->path)))
	{
		((t_entry*)dir->content)->error = strerror(errno);
		ft_print_errors(dir->content, NULL);
		return (1);
	}
	ft_dir_read_init(&file_tree, &subdir_tree, &file_entry, &lengths);
	while ((file = readdir(((t_entry*)dir->content)->stream)))
	{
		if ((!ls->options.a && file->d_name[0] == '.'))
			continue ;
		ft_file_entry_init(file, &file_entry, dir);
		ft_long_format(ls, file_entry, &lengths);
		ft_file_tree_add(ls, &file_tree, &subdir_tree, file_entry);
	}
	ft_print_files(ls, dir, file_tree, &lengths);
	if (ls->options.r_cap && subdir_tree)
		ft_args_dir_management(ls, subdir_tree);
	return (1);
}

int			ft_args_dir_management(t_ls *ls, t_tree *dir)
{
	if (!dir)
		return (1);
	ft_args_dir_management(ls, dir->left);
	ft_dir_read(ls, dir);
	ft_args_dir_management(ls, dir->right);
	return (1);
}
