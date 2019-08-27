/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:18:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/27 16:41:42 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_check_options(char *value, t_ls *ls)
{
	int	i;

	i = 0;
	if (value[i++] != '-' || value[i] == 0)
		return (-1);
	if (value[i] == '-' && value[i + 1] == '\0')
		return (-2);
	while (value[i] != 0 && ft_strnchr(OPTIONS, value[i], ft_strlen(OPTIONS)))
	{
		ls->options.a = (value[i] == 'a') ? 1 : ls->options.a;
		ls->options.r = (value[i] == 'r') ? 1 : ls->options.r;
		ls->options.t = (value[i] == 't') ? 1 : ls->options.t;
		ls->options.r_cap = (value[i] == 'R') ? 1 : ls->options.r_cap;
		if (value[i] == '1' && !(ls->options.l = 0))
			ls->options.one = 1;
		else if (value[i] == 'l' && !(ls->options.one = 0))
			ls->options.l = 1;
		i++;
	}
	if (value[i])
		return (ft_error(e_usage, value + i));
	return (1);
}

static int	ft_opr_list_create(t_list **opr, char **argv, int argc, int *nb)
{
	if (!(ft_lstadd_end(opr,
		ft_lstnew(argv[argc - *nb], ft_strlen(argv[argc - (*nb)--]) + 1))))
		return (ft_error(e_malloc_error, NULL));
	return (1);
}

static int	ft_end_lexer(t_list *opr, int ret_value)
{
	ft_lstdel(&opr, ft_free_opr);
	return (ret_value);
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
		if (flag != -1)
			--nb;
	}
	if (!flag)
		return (ft_error(e_no_print, NULL));
	while (nb)
		if (!(ft_opr_list_create(&opr, argv, argc, &nb)))
			return (ft_end_lexer(opr, 0));
	ft_chose_sort(ls);
	ft_chose_print(ls);
	ft_chose_del(ls);
	ls->fptr_stat = (ls->options.l) ? lstat : stat;
	if (!(ft_three_trees(ls, opr, trees)))
		return (ft_end_lexer(opr, 0));
	return (ft_end_lexer(opr, 1));
}
