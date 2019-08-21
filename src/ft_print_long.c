/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:11:11 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/21 14:41:39 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rights_str(char *rights, t_entry *entry)
{
	rights[0] = entry->type;
	rights[1] = (entry->info.st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (entry->info.st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (entry->info.st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (entry->info.st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (entry->info.st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (entry->info.st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (entry->info.st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (entry->info.st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (entry->info.st_mode & S_IXOTH) ? 'x' : '-';
	if (entry->info.st_mode & S_ISVTX)
	{
		if (rights[9] == 'x')
			rights[9] = 't';
		else
			rights[9] = 'T';
	}
	rights[10] = '\0';
}

void	ft_user_group_str(t_entry *entry, t_lengths *lengths)
{
	if (!entry->user_name)
	{
		entry->user_name = ft_strnew(lengths->user);
		ft_memset(entry->user_name, ' ', lengths->user);
	}
	if (!entry->group_name)
	{
		entry->group_name = ft_strnew(lengths->group);
		ft_memset(entry->group_name, ' ', lengths->group);
	}
}

void	ft_year_time_str(t_entry *entry, char **year_time)
{
	if (entry->time.flag_year)
	{
		*year_time = entry->time.year;
		(*year_time)[4] = '\0';
	}
	else
	{
		*year_time = entry->time.hour_min_sec;
		(*year_time)[5] = '\0';
	}
}

void	ft_print_line_long(void *content, void *additional_content)
{
	char		rights[11];
	char		*year_time;
	t_entry		*entry;
	t_lengths	*lengths;

	entry = (t_entry*)content;
	lengths = (t_lengths*)additional_content;
	ft_rights_str(rights, entry);
	ft_user_group_str(entry, lengths);
	ft_year_time_str(entry, &year_time);
	ft_printf("%s%*d %-*s  %-*s", rights, lengths->links+ 2,
		entry->info.st_nlink, lengths->user, entry->user_name,
		lengths->group, entry->group_name);
	if (entry->type == 'b' || entry->type == 'c')
		ft_printf("%*d,%*d", lengths->major+ 2, entry->major,
			lengths->minor+ 1, entry->minor);
	else
		ft_printf("%*d", lengths->size+ 2, entry->info.st_size);
	ft_printf("%4s%*s%6s%*s", entry->time.month,
		lengths->date + 1, entry->time.date, year_time,
		ft_strlen(entry->name) + 1, entry->name);
	if (((t_entry*)content)->type == 'l')
		ft_printf(" -> %s", ((t_entry*)content)->link);
	ft_putchar('\n');
}
