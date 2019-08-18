/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/18 15:45:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_files(t_ls *ls, t_tree *dir, t_tree *file_tree,
				t_lengths *lengths)
{
	if (ls->print_dir_name_flag < 2)
		ls->print_dir_name_flag = 2;
	else
		ft_printf("%s:\n", ((t_entry*)dir->content)->path);
	ft_tree_inorder_print(file_tree, lengths, ls->fptr_print);
	closedir(((t_entry*)(dir->content))->stream);
	ft_printf("\n");
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
	(*file_entry)->path = ft_strjoin(((t_entry*)dir->content)->path,
		file->d_name);
	(*file_entry)->name = ft_strdup(file->d_name);
	return (1);
}

static void	ft_lengths_update(t_lengths *lengths, t_entry *file_entry)
{
	if ((unsigned int)lengths->links_length < ft_nblen(file_entry->info.st_nlink))
		lengths->links_length = ft_nblen(file_entry->info.st_nlink);
	if ((unsigned int)lengths->date_length < ft_strlen(file_entry->time.day))
		lengths->date_length = ft_strlen(file_entry->time.date);
	if ((unsigned int)lengths->size_length < ft_nblen(file_entry->info.st_size))
		lengths->size_length = ft_nblen(file_entry->info.st_size);
	if (file_entry->user_name && (unsigned int)lengths->user_length < ft_strlen(file_entry->user_name))
		lengths->user_length = ft_strlen(file_entry->user_name);
	if (file_entry->group_name && (unsigned int)lengths->group_length < ft_strlen(file_entry->group_name))
		lengths->group_length = ft_strlen(file_entry->group_name);
}

static int	ft_retrieve_file_infos(t_entry *file_entry)
{
	char			**tab;
	struct passwd	*user;
	struct group	*group;

	if ((user = getpwuid(file_entry->info.st_uid)))
	{
		if ((group = getgrgid(user->pw_gid)))
			file_entry->group_name = group->gr_name;
		else
			file_entry->group_name = NULL;
		file_entry->user_name = user->pw_name;
	}
	else
		file_entry->user_name = NULL;
	tab = ft_strsplit(ctime(&file_entry->info.st_ctimespec.tv_sec), ' ');
	file_entry->time.day = tab[0];
	file_entry->time.month = tab[1];
	file_entry->time.date = tab[2];
	file_entry->time.hour_min_sec = tab[3];
	file_entry->time.year = tab[4];
	return (1);
}

static int	ft_dir_read(t_ls *ls, t_tree *dir)
{
	t_tree			*file_tree;
	t_tree			*subdir_tree;
	t_entry			*file_entry;
	struct dirent	*file;
	t_lengths		lengths;

	if (!((t_entry*)dir->content)->stream)
	{
		ft_print_errors(dir->content, NULL);
		return (1);
	}
	ft_dir_read_init(&file_tree, &subdir_tree, &file_entry, &lengths);
	while ((file = readdir(((t_entry*)dir->content)->stream)))
	{
		if ((!ls->options.a && file->d_name[0] == '.'))
			continue ;
		ft_file_entry_init(file, &file_entry, dir);
		ft_file_tree_add(ls, &file_tree, &subdir_tree, file_entry);
		if (ls->options.l)
		{
			ft_retrieve_file_infos(file_entry);
			ft_lengths_update(&lengths, file_entry);
		}
	}
	ft_print_files(ls, dir, file_tree, &lengths);
	if (ls->options.r_cap && subdir_tree)
		ft_args_dir_management(ls, subdir_tree);
	return (1);
}

int		ft_args_dir_management(t_ls *ls, t_tree *dir)
{
	if (!dir)
		return (1);
	ft_args_dir_management(ls, dir->left);
	ft_dir_read(ls, dir);
	ft_args_dir_management(ls, dir->right);
	return (1);
}
