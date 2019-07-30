/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:25:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/30 17:51:34 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;

	if (argc == 1)
		dirp = opendir(".");
	if (dirp)
		while ((dp = readdir(dirp)) && dp)
			printf("%s\n", dp->d_name);
	return (0);
}
