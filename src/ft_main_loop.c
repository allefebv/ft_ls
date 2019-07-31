/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:37:44 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/31 21:52:41 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_cycle_files(DIR *cur_dir, t_options *options)
{
	struct dirent	*my_file;

	while ((my_file = readdir(cur_dir)) && my_file)
	{

	}
}

void	ft_read_dir(t_options *options, t_list *opr)
{
	DIR		*cur_dir;

	while (opr)
	{
		cur_dir = opendir((char*)opr->content);
		ft_cycle_files(cur_dir, options);
		opr = opr->next;
	}
}
