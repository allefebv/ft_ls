/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/13 17:09:32 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

void	ft_init_main(t_trees_management *th_tr)
{
	th_tr->dirs = (t_tree**)malloc(sizeof(t_tree*));
	*(th_tr->dirs) = NULL;
	th_tr->errors = (t_tree**)malloc(sizeof(t_tree*));
	*(th_tr->errors) = NULL;
	th_tr->files = (t_tree**)malloc(sizeof(t_tree*));
	*(th_tr->files) = NULL;
}

int	main(int argc, char **argv)
{
	t_options			options;
	t_trees_management	trees;
/*
	struct stat		my_stat;
	char			*path;
*/
	ft_init_main(&trees);
	ft_bzero(&options, sizeof(t_options));
	if (argc == 1)
	{
		//path = ft_strdup(".");
		//cur_dir = opendir(path);
	}
	else
	{
		if (!ft_lexer_parser(argc, argv, &options, &trees))
			return (ft_error(e_malloc_error));				//change error
	}
	return (0);
}
