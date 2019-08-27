/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:11:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 14:26:17 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_date(time_t time_file, t_entry *file_entry)
{
	time_t	curr_time;

	time(&curr_time);
	if (time_file < curr_time - SIX_MONTHS || time_file > curr_time)
		return (file_entry->time.flag_year = 1);
	else
		return (file_entry->time.flag_year = 0);
}

void	ft_free_entry(void *content, size_t size)
{
	t_entry	*entry;

	(void)size;
	entry = (t_entry*)content;
	ft_strdel(&entry->path);
	ft_strdel(&entry->name);
	ft_strdel(&entry->link);
	ft_strdel(&entry->group_name);
	ft_strdel(&entry->user_name);
	ft_strdel(&entry->time.day);
	ft_strdel(&entry->time.month);
	ft_strdel(&entry->time.date);
	ft_strdel(&entry->time.hour_min_sec);
	ft_strdel(&entry->time.year);
	free(content);
}

void	ft_free_entry_no_d(void *content, size_t size)
{
	t_entry	*entry;

	(void)size;
	entry = (t_entry*)content;
	if (entry->type != 'd' || ft_strequ(entry->name, ".")
		|| ft_strequ(entry->name, ".."))
		ft_free_entry(content, size);
}

void	ft_free_opr(void *content, size_t size)
{
	free(content);
	(void)size;
}
