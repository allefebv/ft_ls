/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:18:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/19 17:06:44 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_chose_stat_print(t_ls *ls)
{
	if (ls->options.l)
	{
		ls->fptr_stat = lstat;
		ls->fptr_print = ft_print_line_long;
	}
	else
	{
		ls->fptr_stat = stat;
		ls->fptr_print = ft_print_line_cr;
	}
}

static void	ft_chose_sort(t_ls *ls)
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

static int	ft_check_options(char *value, t_ls *ls)
{
	int	i;

	i = 0;
	if (value[i++] != '-')
		return (0);
	if (value[i] == '-')
		return (0);
	while (value[i] != 0 && ft_strnchr(OPTIONS, value[i], ft_strlen(OPTIONS)))
	{
		if (value[i] == 'a')
			ls->options.a = 1;
		else if (value[i] == 'l')
			ls->options.l = 1;
		else if (value[i] == 'r')
			ls->options.r = 1;
		else if (value[i] == 't')
			ls->options.t = 1;
		else
			ls->options.r_cap = 1;
		i++;
	}
	if (value[i])
		return (-1);
	return (1);
}

int			ft_lexer_parser(int argc, char **argv, t_ls *ls,
			t_trees_management *trees)
{
	int		nb;
	int		flag;
	t_list	*opr;

	opr = NULL;
	flag = 1;
	nb = argc - 1;
	while (flag == 1 && nb)
	{
		flag = ft_check_options(argv[argc - nb], ls);
		if (flag)
			--nb;
	}
	if (flag == -1)
		return (0);
	while (nb)
	{
		ft_lstadd_end(&opr,
			ft_lstnew(argv[argc - nb], ft_strlen(argv[argc - nb]) + 1));
		--nb;
	}
	ft_chose_sort(ls);
	ft_chose_stat_print(ls);
	ft_three_trees(ls, opr, trees);
	return (1);
}
