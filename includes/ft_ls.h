/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:29:48 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/18 15:24:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include "libft.h"

# define OPTIONS "alrtR"

typedef struct	s_trees_management
{
	t_tree		**errors;
	t_tree		**files;
	t_tree		**dirs;
}				t_trees_management;

typedef struct	s_options
{
	int	a;
	int l;
	int r;
	int	t;
	int	r_cap;
}				t_options;

typedef struct	s_ls
{
	t_options	options;
	int			print_dir_name_flag;
	int			is_arg_error_tree;
	int			is_arg_files_tree;
	int			(*fptr_sort)(void*, void*);
	int			(*fptr_stat)(const char*, struct stat*);
	void		(*fptr_print)(void*, void*);
}				t_ls;

typedef struct	s_time
{
	char		*year;
	char		*month;
	char		*day;
	char		*date;
	char		*hour_min_sec;
}				t_time;


typedef struct	s_entry
{
	char		*path;
	char		*name;
	char		*error;
	char		type;
	t_time		time;
	char		*user_name;
	char		*group_name;
	DIR			*stream;
	struct stat	info;
}				t_entry;

typedef struct	s_lengths
{
	int			links_length;
	int			user_length;
	int			group_length;
	int			size_length;
	int			date_length;
}				t_lengths;

typedef enum	e_errors
{
	e_malloc_error,
}				t_errors;

char	ft_file_mode(mode_t mode);
int		ft_lexer_parser(int argc, char **argv, t_ls *ls,
			t_trees_management *trees);
int		ft_args_dir_management(t_ls *ls, t_tree *dir);
int		ft_error(t_errors error_type);
int		ft_three_trees(t_ls *ls, t_list *opr, t_trees_management *trees);
void	ft_file_tree_add(t_ls *ls, t_tree **file_tree, t_tree **subdir_tree,
			t_entry *file_entry);

int		ft_name_sort(void *root_content, void *node_content);
int		ft_time_name_sort(void *root_content, void *node_content);
int		ft_rev_name_sort(void *root_content, void *node_content);
int		ft_rev_time_name_sort(void *root_content, void *node_content);

void	ft_print_path(void *content, void *additional_content);
void	ft_print_line_long(void *content, void *additional_content);
void	ft_print_line_cr(void *content, void *additional_content);
void	ft_print_path_space(void *content, void *additional_content);
void	ft_print_errors(void *content, void *additional_content);

void	ft_check_dir_end(char **path);

#endif
