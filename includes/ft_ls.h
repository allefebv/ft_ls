/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:29:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/31 21:52:48 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>
#include <dirent.h>
#include "libft.h"

#define OPTIONS "alrtR"

typedef struct	s_options
{
	int	a;
	int l;
	int r;
	int	t;
	int	r_cap;
}				t_options;

char	file_mode(struct stat *file);
int		lexer_parser(int argc, char **argv, t_options *options, t_list **opr);

#endif
