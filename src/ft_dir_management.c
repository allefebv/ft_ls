/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/23 12:49:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	{
		if (!((*file_entry)->path = ft_strjoin(((t_entry*)dir->content)->path,
			file->d_name)))
			return (ft_error(e_malloc_error));
	}
	else
	{
		if (!((*file_entry)->path =
			ft_strjoin(((t_entry*)dir->content)->path, "/")))
			return (ft_error(e_malloc_error));
		if (!((*file_entry)->path = ft_strextend((*file_entry)->path,
			file->d_name)))
			return (ft_error(e_malloc_error));
	}
	if (!((*file_entry)->name = ft_strdup(file->d_name)))
		return (ft_error(e_malloc_error));
	lstat((*file_entry)->path, &(*file_entry)->info);
	(*file_entry)->type = ft_file_mode(((*file_entry)->info.st_mode));
	return (1);
}

static int	ft_dir_read(t_ls *ls, t_tree *dir, t_tree **subdir_tree)
{
	struct dirent	*file;
	t_lengths		lengths;
	t_entry			*file_entry;
	t_tree			*file_tree;

	ft_dir_read_init(&file_tree, subdir_tree, &file_entry, &lengths);
	while ((file = readdir(((t_entry*)dir->content)->stream)))
	{
		if (!(((t_entry*)dir->content)->info.st_mode & S_IXUSR))
			break ;
		if ((!ls->options.a && file->d_name[0] == '.'))
			continue ;
		if (!(ft_file_entry_init(file, &file_entry, dir)))
			return (ft_error(e_no_print));
		if (!(ft_long_format(ls, file_entry, &lengths)))
			return (ft_error(e_no_print));
		if (!(ft_file_tree_add(ls, &file_tree, subdir_tree, file_entry)))
			return (ft_error(e_no_print));
	}
	ft_print_files(ls, dir, file_tree, &lengths);
	ft_treedel(&file_tree, ls->fptr_del);
	return (1);
}

static int	ft_dir_open_read_print(t_ls *ls, t_tree *dir)
{
	t_tree			*subdir_tree;

	if (!(((t_entry*)dir->content)->stream =
		opendir(((t_entry*)dir->content)->path)))
	{
		if (!ls->first)
			ft_printf("\n");
		((t_entry*)dir->content)->error = strerror(errno);
		ft_print_open_error(dir->content, NULL);
		return (1);
	}
	ft_dir_read(ls, dir, &subdir_tree);
	if (ls->options.r_cap && subdir_tree)
		ft_dir_tree_browse(ls, subdir_tree);
	return (1);
}

int			ft_dir_tree_browse(t_ls *ls, t_tree *dir)
{
	if (!dir)
		return (1);
	if (!(ft_dir_tree_browse(ls, dir->left)))
		return (ft_error(e_no_print));
	if (!(ft_dir_open_read_print(ls, dir)))
		return (ft_error(e_no_print));
	if (!(ft_dir_tree_browse(ls, dir->right)))
		return (ft_error(e_no_print));
	ft_treedel(&dir, ft_free_entry);
	return (1);
}
