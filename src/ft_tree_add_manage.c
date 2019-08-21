/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_add_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:10:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/21 16:36:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_check_dir(char *name)
{
	return (ft_strequ(name, ".") || ft_strequ(name, ".."));
}

static void	ft_cap_r_tree(t_ls *ls, t_entry *file_entry, t_tree **subdir_tree)
{
	ft_treeadd(subdir_tree,
		ft_treenew_ptr(file_entry), ls->fptr_sort);
}

void		ft_file_tree_add(t_ls *ls, t_tree **file_tree, t_tree **subdir_tree,
			t_entry *file_entry)
{
	ft_treeadd(file_tree, ft_treenew_ptr(file_entry), ls->fptr_sort);
	if (ls->options.r_cap
		&& S_ISDIR(file_entry->info.st_mode)
		&& !ft_check_dir(file_entry->name))
		ft_cap_r_tree(ls, file_entry, subdir_tree);
}
