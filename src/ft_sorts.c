/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:35:07 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/14 11:37:52 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_name_sort(void *root_content, void *node_content)
{
	return (ft_strcmp((char*)((t_entry*)(root_content))->path,
		(char*)((t_entry*)(node_content))->path));
}

int		ft_time_name_sort(void *root_content, void *node_content)
{
	if (((t_entry*)root_content)->info.st_mtimespec.tv_sec <
		((t_entry*)node_content)->info.st_mtimespec.tv_sec)
		return (1);
	else if (((t_entry*)root_content)->info.st_mtimespec.tv_sec >
			((t_entry*)node_content)->info.st_mtimespec.tv_sec)
		return (-1);
	else
		return (ft_strcmp((char*)((t_entry*)(root_content))->path,
			(char*)((t_entry*)(node_content))->path));
}

int		ft_rev_name_sort(void *root_content, void *node_content)
{
	return (ft_strcmp((char*)((t_entry*)(node_content))->path,
		(char*)((t_entry*)(root_content))->path));
}

int		ft_rev_time_name_sort(void *root_content, void *node_content)
{
	if (((t_entry*)root_content)->info.st_mtimespec.tv_sec <
		((t_entry*)node_content)->info.st_mtimespec.tv_sec)
		return (-1);
	else if (((t_entry*)root_content)->info.st_mtimespec.tv_sec >
			((t_entry*)node_content)->info.st_mtimespec.tv_sec)
		return (1);
	else
		return (ft_strcmp((char*)((t_entry*)(node_content))->path,
		(char*)((t_entry*)(root_content))->path));
}
