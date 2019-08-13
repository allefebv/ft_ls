/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/13 12:43:28 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_cycle_files(DIR *cur_dir, t_options *options)
{
	struct dirent	*my_file;

	(void)options;
	while ((my_file = readdir(cur_dir)) && my_file)
	{

	}
}

void	ft_read_dir(t_options *options, t_list *opr)
{
	DIR			*cur_dir;
	struct stat	data;

	while (opr)
	{
		if ((cur_dir = opendir((char*)opr->content)))
			ft_cycle_files(cur_dir, options);
		else if (!lstat((char*)opr->content, &data))
			return ;
		opr = opr->next;
	}
}
