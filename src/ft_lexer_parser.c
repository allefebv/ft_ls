/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:18:18 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/31 21:52:44 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_check_options(char *value, t_options *options)
{
	int	i;

	i = 0;
	if (value[i++] != '-')
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

int		ft_lexer_parser(int argc, char **argv, t_options *options, t_list **opr)
{
	int	nb;
	int	flag;

	flag = 1;
	nb = argc;
	while (argc && flag == 1)
		flag = ft_check_options(argv[nb - --argc], options);
	if (flag == -1)
		return (0);
	while (argc)
	{
		ft_lstadd_end(opr,
			ft_lstnew(argv[nb - argc], ft_strlen(argv[nb - argc]) + 1));
		--argc;
	}
	return (1);
}
