/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_trees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:43:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/13 17:45:35 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
static void	ft_file_tree(void)
{
	return ;
}

static void	ft_error_tree(void)
{
	return ;
}
*/

void	ft_dir_tree(t_entry *entry, t_trees_management trees)
{
	lstat(entry->path, &entry->info);
	ft_treeadd(trees.dirs, ft_treenew(entry, sizeof(t_entry*)), trees.fptr);
}

int	ft_three_trees(t_list *opr, t_trees_management trees)
{
	t_entry	*entry;

	while (opr)
	{
		if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
			return (ft_error(e_malloc_error));
		entry->path = (char*)opr->content;
		if ((entry->stream = opendir(entry->path)))
			ft_dir_tree(entry, trees);
		opr = opr->next;
	}
	ft_tree_inorder_print(*trees.dirs, ft_print_path);
	return (1);
}
