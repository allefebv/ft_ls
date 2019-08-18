/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/18 14:56:17 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

void	ft_init_main(t_trees_management *trees, t_ls *ls)
{
	trees->errors = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->errors) = NULL;
	trees->files = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->files) = NULL;
	trees->dirs = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->dirs) = NULL;
	ft_bzero(ls, sizeof(t_ls));
}

int	main(int argc, char **argv)
{
	t_options			options;
	t_trees_management	trees;
	t_ls				ls;

	ft_init_main(&trees, &ls);
	ft_bzero(&options, sizeof(t_options));
	if (!ft_lexer_parser(argc, argv, &ls, &trees))
		return (ft_error(e_malloc_error));				//change error
	ft_args_dir_management(&ls, *trees.dirs);
	return (0);
}
