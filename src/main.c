/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/31 21:52:45 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_options		options;
	t_list			*opr;
/*
	DIR				*cur_dir;
	struct dirent	*my_file;
	struct stat		my_stat;
	char			*path;
	char			*str;
*/
	opr = NULL;
	ft_bzero(&options, sizeof(t_options));

	if (argc == 1)
	{
		//path = ft_strdup(".");
		//cur_dir = opendir(path);
	}
	else
	{
		if (!ft_lexer_parser(argc, argv, &options, &opr))
			return (ft_error);
		//path = ft_strdup(argv[1]);
		//cur_dir = opendir(path);
	}
	ft_printf("a = %d\nl = %d\nr = %d\nt = %d\nR = %d\n",
		options.a, options.l, options.r, options.t, options.r_cap);
	while (opr)
	{
		ft_lstprint_str(opr);
		opr = opr->next;
	}
/*
	if (cur_dir)
	{
		while ((my_file = readdir(cur_dir)) && my_file)
		{
			asprintf(&str, "%s/%s", path, my_file->d_name);
			lstat(str, &my_stat);
			ft_printf("%c\n", file_mode(&my_stat));
		}
	}
*/
	return (0);
}
