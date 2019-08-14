/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/14 19:31:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

void	ft_init_main(t_trees_management *trees)
{
	trees->errors = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->errors) = NULL;
	trees->count_errors = 0;
	trees->files = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->files) = NULL;
	trees->count_files = 0;
	trees->dirs = (t_tree**)malloc(sizeof(t_tree*));
	*(trees->dirs) = NULL;
	trees->count_dirs = 0;
}

int	main(int argc, char **argv)
{
	t_options			options;
	t_trees_management	trees;

	ft_init_main(&trees);
	ft_bzero(&options, sizeof(t_options));
	if (!ft_lexer_parser(argc, argv, &options, &trees))
		return (ft_error(e_malloc_error));				//change error
	ft_dir_management(&trees, &options, *trees.dirs);
	return (0);
}
