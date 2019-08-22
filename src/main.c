/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/22 21:44:27 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int	ft_init_main(t_trees_management *trees, t_ls *ls)
{
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
		return (ft_error(e_no_print));
	ft_bzero(&options, sizeof(t_options));
	if (!ft_lexer_parser(argc, argv, &ls, &trees))
		return (ft_error(e_no_print));
	if (!(ft_dir_tree_browse(&ls, *trees.dirs)))
		return (ft_error(e_no_print));
	return (0);
}
