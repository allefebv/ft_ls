/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:11:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 15:30:31 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_dir_end(char **path)
{
	char	*tmp;

	if ((*path)[ft_strlen(*path) - 1] != '/')
	{
		tmp = *path;
		*path = ft_strjoin(*path, "/");
		ft_strdel(&tmp);
	}
}
