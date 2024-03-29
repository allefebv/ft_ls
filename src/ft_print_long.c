/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:11:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/28 12:17:44 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_rights_str(char *rights, t_entry *entry)
{
	char	*namebuf;

	namebuf = NULL;
	rights[0] = entry->type;
	rights[1] = (entry->info.st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (entry->info.st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (entry->info.st_mode & S_IXUSR) ? 'x' : '-';
	if (entry->info.st_mode & S_ISUID)
		rights[3] = (rights[3] == '-') ? 'S' : 's';
	rights[4] = (entry->info.st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (entry->info.st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (entry->info.st_mode & S_IXGRP) ? 'x' : '-';
	if (entry->info.st_mode & S_ISGID)
		rights[6] = (rights[6] == '-') ? 'S' : 's';
	rights[7] = (entry->info.st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (entry->info.st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (entry->info.st_mode & S_IXOTH) ? 'x' : '-';
	if (entry->info.st_mode & S_ISVTX)
		rights[9] = (rights[9] == 'x') ? 't' : 'T';
	rights[10] = (acl_get_file(entry->path, ACL_TYPE_EXTENDED)) ? '+' : ' ';
	if (listxattr(entry->path, namebuf, 0, XATTR_NOFOLLOW) > 0)
		rights[10] = '@';
	rights[11] = '\0';
}

static int	ft_user_group_str(t_entry *entry, t_lengths *lengths)
{
	if (!entry->user_name)
	{
		if (!(entry->user_name = ft_strnew(lengths->user)))
			return (0);
		ft_memset(entry->user_name, ' ', lengths->user);
	}
	if (!entry->group_name)
	{
		if (!(entry->group_name = ft_strnew(lengths->group)))
			return (0);
		ft_memset(entry->group_name, ' ', lengths->group);
	}
	return (1);
}

static void	ft_year_time_str(t_entry *entry, char **year_time)
{
	if (entry->time.flag_year)
	{
		*year_time = entry->time.year;
		if (ft_strlen(entry->time.year) > 5)
		{
			entry->time.year_padding = 7;
			(*year_time)[5] = '\0';
		}
		else
		{
			entry->time.year_padding = 6;
			(*year_time)[4] = '\0';
		}
	}
	else
	{
		*year_time = entry->time.hour_min_sec;
		entry->time.year_padding = 6;
		(*year_time)[5] = '\0';
	}
}

void		ft_print_line_long(void *content, void *additional_content)
{
	char		rights[12];
	char		*year_time;
	t_entry		*entry;
	t_lengths	*lengths;

	entry = (t_entry*)content;
	lengths = (t_lengths*)additional_content;
	ft_rights_str(rights, entry);
	if (!(ft_user_group_str(entry, lengths)))
		return ;
	ft_year_time_str(entry, &year_time);
	ft_printf("%s %*d %-*s  %-*s  ", rights, lengths->links,
		entry->info.st_nlink, lengths->user, entry->user_name,
		lengths->group, entry->group_name);
	if (entry->type == 'b' || entry->type == 'c')
		ft_printf("%*d,%*d", lengths->major + 1, entry->major,
			lengths->minor + 1, entry->minor);
	else
		ft_printf("%*d", lengths->size, entry->info.st_size);
	ft_printf("%4s%3s%*s%*s", entry->time.month, entry->time.date,
		entry->time.year_padding, year_time, ft_strlen(entry->name) + 1,
		entry->name);
	if (((t_entry*)content)->type == 'l')
		ft_printf(" -> %s", ((t_entry*)content)->link);
	ft_putchar('\n');
}
