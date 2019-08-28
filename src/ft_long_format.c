/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:01:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/28 14:07:43 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lengths_update(t_lengths *lengths, t_entry *file_entry)
{
	if ((unsigned int)lengths->links < ft_nblen(file_entry->info.st_nlink))
		lengths->links = ft_nblen(file_entry->info.st_nlink);
	if ((unsigned int)lengths->date < ft_strlen(file_entry->time.day))
		lengths->date = ft_strlen(file_entry->time.date);
	if ((unsigned int)lengths->size < ft_nblen(file_entry->info.st_size))
		lengths->size = ft_nblen(file_entry->info.st_size);
	if (file_entry->user_name
		&& (unsigned int)lengths->user < ft_strlen(file_entry->user_name))
		lengths->user = ft_strlen(file_entry->user_name);
	if (file_entry->group_name
		&& (unsigned int)lengths->group < ft_strlen(file_entry->group_name))
		lengths->group = ft_strlen(file_entry->group_name);
	if (file_entry->major
		&& (unsigned int)lengths->major < ft_nblen(file_entry->major))
		lengths->major = ft_nblen(file_entry->major);
	if (file_entry->minor
		&& (unsigned int)lengths->minor < ft_nblen(file_entry->minor))
		lengths->minor = ft_nblen(file_entry->minor);
	if (lengths->minor + lengths->major + 1 > lengths->size)
		lengths->size = lengths->minor + lengths->major + 2;
	lengths->blocks += file_entry->info.st_blocks;
}

static int	ft_retrieve_specific(t_entry *file_entry)
{
	if (file_entry->type == 'l')
	{
		if (!(file_entry->link = ft_strnew(file_entry->info.st_size + 1)))
			return (ft_error(e_malloc_error, NULL));
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

static void	ft_group_user_info(t_entry *file_entry, char **tab)
{
	file_entry->time.day = tab[0];
	file_entry->time.month = tab[1];
	file_entry->time.date = tab[2];
	if (!ft_check_date(file_entry->info.st_mtimespec.tv_sec, file_entry))
	{
		file_entry->time.hour_min_sec = tab[3];
		ft_strdel(&tab[4]);
	}
	else
	{
		file_entry->time.year = tab[4];
		ft_strdel(&tab[3]);
	}
}

static int	ft_retrieve_file_infos(t_entry *file_entry)
{
	char			**tab;
	struct passwd	*user;
	struct group	*group;

	if ((user = getpwuid(file_entry->info.st_uid)))
		file_entry->user_name = ft_strdup(user->pw_name);
	else
		file_entry->user_name = ft_itoa(file_entry->info.st_uid);
	if ((group = getgrgid(file_entry->info.st_gid)))
		file_entry->group_name = ft_strdup(group->gr_name);
	else
		file_entry->group_name = ft_itoa(file_entry->info.st_gid);
	if (!(tab = ft_strsplit(ctime(&file_entry->info.st_mtimespec.tv_sec), ' ')))
		return (ft_error(e_malloc_error, NULL));
	ft_group_user_info(file_entry, tab);
	if (!(ft_retrieve_specific(file_entry)))
	{
		free(tab);
		return (ft_error(e_no_print, NULL));
	}
	free(tab);
	return (1);
}

int			ft_long_format(t_ls *ls, t_entry *file_entry, t_lengths *lengths)
{
	if (ls->options.l)
	{
		if (!(ft_retrieve_file_infos(file_entry)))
			return (ft_error(e_no_print, NULL));
		ft_lengths_update(lengths, file_entry);
	}
	return (1);
}
