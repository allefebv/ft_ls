/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:52:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/16 16:55:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(void *content)
{
	ft_printf("%s:\n", (char*)((t_entry*)(content))->path);
}

void	ft_print_line_cr(void *content)
{
	ft_printf("%s\n", (char*)((t_entry*)(content))->name);
}

void	ft_print_line_long(void *content)
{
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
	ft_printf("\n");
}

void	ft_print_path_space(void *content)
{
	ft_printf("%s ", (char*)((t_entry*)(content))->path);
}

void	ft_print_errors(void *content)
{
	ft_printf("ls: %s: %s\n", (char*)((t_entry*)(content))->path,
		(char*)((t_entry*)(content))->error);
}
