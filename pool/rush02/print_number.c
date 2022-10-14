/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:18:28 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 16:25:11 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handle_block(t_dict *dict, char *nb, int digits)
{
	if (digits == 1)
		print_units(dict, nb, digits);
	if (digits == 2)
		print_tens(dict, nb, digits);
	if (digits == 3)
		print_hundreds(dict, nb, digits);
}

void	ft_ultimate_printer(t_dict *dict, char *nb, int blocks)
{
	int	i;

	i = 0;
	while (i < blocks)
	{
		handle_block(dict, nb, 3);
		ft_putstr(" ");
		if (i < blocks - 1 && (nb[0] != '0' || nb[1] != '0' || nb[2] != '0'))
		{
			nb = nb + 3;
			ft_putstr(" ");
			ft_putstr(ft_map_search2(dict, ft_strlen(nb) + 1));
		}
		else
			nb = nb + 3;
	i++;
	}
}

void	print_number(t_dict *dict, char *nb)
{
	int	first_block_size;
	int	digits;
	int	blocks;

	digits = ft_strlen(nb);
	first_block_size = digits % 3;
	blocks = digits / 3;
	if (digits < 4)
	{
		handle_block(dict, nb, digits);
		return ;
	}
	if (first_block_size > 0)
	{
		handle_block(dict, nb, first_block_size);
		ft_putstr(" ");
		ft_putstr(ft_map_search2(dict, digits - first_block_size + 1));
		ft_putstr(" ");
	}
	ft_ultimate_printer(dict, nb + first_block_size, blocks);
}
