/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:18:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/14 19:05:28 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_chose_stat_print(t_options *options, t_trees_management *trees)
{
	if (options->l)
	{
		trees->fptr_stat = lstat;
		trees->fptr_print = ft_print_line_long;
	}
	else
	{
		trees->fptr_stat = stat;
		trees->fptr_print = ft_print_line_cr;
	}
}

static void	ft_chose_sort(t_options *options, t_trees_management *trees)
{
	if (options->t && !options->r)
		trees->fptr_sort = ft_time_name_sort;
	else if (options->t && options->r)
		trees->fptr_sort = ft_rev_time_name_sort;
	else if (options->r)
		trees->fptr_sort = ft_rev_name_sort;
	else
		trees->fptr_sort = ft_name_sort;
}

static int	ft_check_options(char *value, t_options *options)
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
			options->a = 1;
		else if (value[i] == 'l')
			options->l = 1;
		else if (value[i] == 'r')
			options->r = 1;
		else if (value[i] == 't')
			options->t = 1;
		else
			options->r_cap = 1;
		i++;
	}
	if (value[i])
		return (-1);
	return (1);
}

int		ft_lexer_parser(int argc, char **argv, t_options *options,
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
		flag = ft_check_options(argv[argc - nb], options);
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
	ft_chose_sort(options, trees);
	ft_chose_stat_print(options, trees);
	ft_three_trees(opr, trees);
	return (1);
}
