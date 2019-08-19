/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:11:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/19 17:07:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_dir_end(char **path)
{
	char	*tmp;

	if ((*path)[ft_strlen(*path) - 1] != '/')
	{
		tmp = *path;
		*path = ft_strjoin(*path, "/");
		ft_strdel(&tmp);
	}
}

int		ft_check_date(time_t time_file, t_entry *file_entry)
{
	time_t	curr_time;

	time(&curr_time);
	if (time_file < curr_time - SIX_MONTHS || time_file > curr_time)
		return (file_entry->time.flag_year = 1);
	else
		return (file_entry->time.flag_year = 0);
}
