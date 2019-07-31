/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/31 13:29:03 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		file;

	(void)argc;
	(void)argv;
	dirp = opendir(".");
	if (dirp)
		while ((dp = readdir(dirp)) && dp)
			ft_printf("%s\n", dp->d_name);
	file_mode(&file);
	return (0);
}
