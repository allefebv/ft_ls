/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fptr_define.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:14:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 16:43:37 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_chose_print(t_ls *ls)
{
	if (ls->options.l)
		ls->fptr_print = ft_print_line_long;
	else
		ls->fptr_print = ft_print_line_cr;
}

void	ft_chose_sort(t_ls *ls)
{
	if (ls->options.t && !ls->options.r)
		ls->fptr_sort = ft_time_name_sort;
	else if (ls->options.t && ls->options.r)
		ls->fptr_sort = ft_rev_time_name_sort;
	else if (ls->options.r)
		ls->fptr_sort = ft_rev_name_sort;
	else
		ls->fptr_sort = ft_name_sort;
}

void	ft_chose_del(t_ls *ls)
{
	if (ls->options.r_cap)
		ls->fptr_del = ft_free_entry_no_d;
	else
		ls->fptr_del = ft_free_entry;
}
