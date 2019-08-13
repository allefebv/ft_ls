/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:41:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/12 14:36:56 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_file_mode(struct stat *my_stat)
{
	mode_t	val;

	val = (my_stat->st_mode & S_IFMT);
	if (val & S_IFDIR)
		return ('d');
	else if (val & S_IFIFO)
		return ('p');
	else if (val & S_IFCHR)
		return ('c');
	else if (val & S_IFBLK)
		return ('b');
	else if (val & S_IFREG)
		return ('-');
	else if (val & S_IFLNK)
		return ('l');
	else if (val & S_IFSOCK)
		return ('s');
	return (0);
}
