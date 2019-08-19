/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/19 16:30:34 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_files(t_ls *ls, t_tree *dir, t_tree *file_tree,
				t_lengths *lengths)
{
	int	size;
	char	*tmp;

	if (ls->print_dir_name_flag < 2)
		ls->print_dir_name_flag = 2;
	else
	{
		ft_printf("\n");
		size = ft_strrchr(((t_entry*)dir->content)->path, '/') - ((t_entry*)dir->content)->path;
		tmp = ft_strsub(((t_entry*)dir->content)->path, 0, size);
		ft_printf("%s:\n", tmp);
		free(tmp);
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

static int	ft_file_entry_init(t_ls *ls, struct dirent *file,
				t_entry **file_entry, t_tree *dir)
{
	if (!(*file_entry = (t_entry*)malloc(sizeof(t_entry))))
		return (ft_error(e_malloc_error));
	ft_bzero(*file_entry, sizeof(t_entry));
	(*file_entry)->path = ft_strjoin(((t_entry*)dir->content)->path,
		file->d_name);
	(*file_entry)->name = ft_strdup(file->d_name);
	ls->fptr_stat((*file_entry)->path, &(*file_entry)->info);
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
	if (file_entry->major && (unsigned int)lengths->major_length < ft_nblen(file_entry->major))
		lengths->major_length = ft_nblen(file_entry->major);
	if (file_entry->minor && (unsigned int)lengths->minor_length < ft_nblen(file_entry->minor))
		lengths->minor_length = ft_nblen(file_entry->minor);
	if (lengths->minor_length + lengths->major_length + 1 > lengths->size_length)
		lengths->size_length = lengths->minor_length + lengths->major_length + 2;
	lengths->blocks += file_entry->info.st_blocks;
}

static int	ft_check_date(time_t time_file, t_entry *file_entry)
{
	time_t	curr_time;

	time(&curr_time);
	if (time_file < curr_time - SIX_MONTHS || time_file > curr_time)
		return (file_entry->time.flag_year = 1);
	else
		return (file_entry->time.flag_year = 0);
}

static int	ft_retrieve_file_infos(t_entry *file_entry)
{
	char			**tab;
	struct passwd	*user;
	struct group	*group;

	if ((user = getpwuid(file_entry->info.st_uid)))
		file_entry->user_name = user->pw_name;
	else
		file_entry->user_name = NULL;
	if ((group = getgrgid(file_entry->info.st_gid)))
		file_entry->group_name = group->gr_name;
	else
		file_entry->group_name = NULL;
	tab = ft_strsplit(ctime(&file_entry->info.st_mtimespec.tv_sec), ' ');
	file_entry->time.day = tab[0];
	file_entry->time.month = tab[1];
	file_entry->time.date = tab[2];
	if (!ft_check_date(file_entry->info.st_mtimespec.tv_sec, file_entry))
		file_entry->time.hour_min_sec = tab[3];
	else
		file_entry->time.year = tab[4];
	if (file_entry->type == 'l')
	{
		file_entry->link = ft_strnew(file_entry->info.st_size + 1);
		readlink(file_entry->path, file_entry->link,
			file_entry->info.st_size + 1);
	}
	if (file_entry->type == 'c' || file_entry->type == 'b')
	{
		file_entry->major = major(file_entry->info.st_rdev);
		file_entry->minor = minor(file_entry->info.st_rdev);
	}
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
		ft_file_entry_init(ls, file, &file_entry, dir);
		if (ls->options.l)
		{
			file_entry->type = ft_file_mode((file_entry->info.st_mode));
			ft_retrieve_file_infos(file_entry);
			ft_lengths_update(&lengths, file_entry);
		}
		ft_file_tree_add(ls, &file_tree, &subdir_tree, file_entry);
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
