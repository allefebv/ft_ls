/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:39:58 by allefebv          #+#    #+#             */
/*   Updated: 2019/08/12 14:40:28 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	//tests that the options are stored appropriately
	ft_printf("a = %d\nl = %d\nr = %d\nt = %d\nR = %d\n",
		options.a, options.l, options.r, options.t, options.r_cap);
	//tests that the operands are stored appropriately
	while (opr)
	{
		ft_lstprint_str(opr);
		opr = opr->next;
	}
