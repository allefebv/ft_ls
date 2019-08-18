/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:52:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/18 15:49:13 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s:\n", (char*)((t_entry*)(content))->path);
}

void	ft_print_line_cr(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s\n", (char*)((t_entry*)(content))->name);
}

void	ft_print_line_long(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%c", ft_file_mode(((t_entry*)content)->info.st_mode));
	ft_printf((((t_entry*)content)->info.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((((t_entry*)content)->info.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("%*d", ((t_lengths*)additional_content)->links_length + 1,
		((t_entry*)content)->info.st_nlink);
	if (((t_entry*)content)->user_name)
		ft_printf("%*s", ((t_lengths*)additional_content)->user_length + 1,
			((t_entry*)content)->user_name);
	else
		ft_printf("%*c", ((t_lengths*)additional_content)->user_length + 1,
			' ');
	if (((t_entry*)content)->group_name)
		ft_printf("%*s", ((t_lengths*)additional_content)->group_length + 2,
			((t_entry*)content)->group_name);
	else
		ft_printf("%*c", ((t_lengths*)additional_content)->group_length + 1,
			' ');
	ft_printf("%*d", ((t_lengths*)additional_content)->size_length + 2,
		((t_entry*)content)->info.st_size);
	ft_printf("%4s", ((t_entry*)content)->time.month);
	ft_printf("%*s", ((t_lengths*)additional_content)->date_length + 1,
		((t_entry*)content)->time.date);
	ft_printf("%6.5s", ((t_entry*)content)->time.hour_min_sec);
	ft_printf("%*s", ft_strlen(((t_entry*)content)->name) + 1,
		((t_entry*)content)->name);
	ft_printf("\n");
}

void	ft_print_path_space(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("%s ", (char*)((t_entry*)(content))->path);
}

void	ft_print_errors(void *content, void *additional_content)
{
	(void)additional_content;
	ft_printf("ls: %s: %s\n", (char*)((t_entry*)(content))->path,
		(char*)((t_entry*)(content))->error);
}
