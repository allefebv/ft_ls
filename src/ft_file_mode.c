/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:41:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 16:47:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_file_mode(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISREG(mode))
		return ('-');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	return (0);
}
