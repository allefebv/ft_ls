/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/23 12:50:47 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static int	ft_end_main(t_trees_management trees, int ret_val)
{
	ft_treedel(trees.dirs, ft_free_entry);
	free(trees.dirs);
	ft_treedel(trees.errors, ft_free_entry);
	free(trees.errors);
	ft_treedel(trees.files, ft_free_entry);
	free(trees.files);
	return (ret_val);
}

static int	ft_init_main(t_trees_management *trees, t_ls *ls)
{
	ft_bzero(trees, sizeof(t_trees_management));
	if (!(trees->errors = (t_tree**)malloc(sizeof(t_tree*))))
		return (ft_error(e_malloc_error));
	*(trees->errors) = NULL;
	if (!(trees->files = (t_tree**)malloc(sizeof(t_tree*))))
		return (ft_error(e_malloc_error));
	*(trees->files) = NULL;
	if (!(trees->dirs = (t_tree**)malloc(sizeof(t_tree*))))
		return (ft_error(e_malloc_error));
	*(trees->dirs) = NULL;
	ft_bzero(ls, sizeof(t_ls));
	ls->first = 1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_options			options;
	t_trees_management	trees;
	t_ls				ls;

	if (!(ft_init_main(&trees, &ls)))
		return (ft_end_main(trees, -1));
	ft_bzero(&options, sizeof(t_options));
	if (!ft_lexer_parser(argc, argv, &ls, &trees))
		return (ft_end_main(trees, -1));
	if (!(ft_dir_tree_browse(&ls, *trees.dirs)))
		return (ft_end_main(trees, -1));
	return (ft_end_main(trees, 0));
}
