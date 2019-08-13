/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:29:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/13 17:16:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft.h"

# define OPTIONS "alrtR"

typedef struct	s_options
{
	int	a;
	int l;
	int r;
	int	t;
	int	r_cap;
}				t_options;

typedef struct	s_trees_management
{
	t_tree		**errors;
	t_tree		**files;
	t_tree		**dirs;
	int			(*fptr)(void*, void*);
}				t_trees_management;

typedef struct	s_entry
{
	char		*path;
	char		*name;
	DIR			*stream;
	struct stat	info;
}				t_entry;

typedef enum	e_errors
{
	e_malloc_error,
}				t_errors;

char	file_mode(struct stat *file);
int		ft_lexer_parser(int argc, char **argv, t_options *options,
			t_trees_management *trees);
void	ft_read_dir(t_options *options, t_list *opr);
int		ft_error(t_errors error_type);
int		ft_three_trees(t_list *opr, t_trees_management th_tr);

int		ft_name_sort(void *root_content, void *node_content);
int		ft_time_name_sort(void *root_content, void *node_content);
int		ft_rev_name_sort(void *root_content, void *node_content);
int		ft_rev_time_name_sort(void *root_content, void *node_content);

void	ft_print_path(void *content);

#endif
