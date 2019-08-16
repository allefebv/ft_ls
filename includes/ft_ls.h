/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:29:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 16:46:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
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
	int			count_errors;
	t_tree		**files;
	int			count_files;
	t_tree		**dirs;
	int			count_dirs;
	int			(*fptr_sort)(void*, void*);
	int			(*fptr_stat)(const char *, struct stat *);
	void		(*fptr_print)(void *content);

}				t_trees_management;

typedef struct	s_entry
{
	char		*path;
	char		*name;
	char		*error;
	char		type;
	DIR			*stream;
	struct stat	info;
}				t_entry;

typedef enum	e_errors
{
	e_malloc_error,
}				t_errors;

char	ft_file_mode(mode_t mode);
int		ft_lexer_parser(int argc, char **argv, t_options *options,
			t_trees_management *trees);
int		ft_args_dir_management(t_trees_management *trees, t_options *options,
			t_tree *dir);
int		ft_error(t_errors error_type);
int		ft_three_trees(t_list *opr, t_trees_management *trees);

int		ft_name_sort(void *root_content, void *node_content);
int		ft_time_name_sort(void *root_content, void *node_content);
int		ft_rev_name_sort(void *root_content, void *node_content);
int		ft_rev_time_name_sort(void *root_content, void *node_content);

void	ft_print_path(void *content);
void	ft_print_line_long(void *content);
void	ft_print_line_cr(void *content);
void	ft_print_path_space(void *content);
void	ft_print_errors(void *content);

void	ft_check_dir_end(char **path);

#endif
