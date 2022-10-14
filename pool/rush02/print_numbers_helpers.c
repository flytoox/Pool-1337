/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:25:33 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 16:29:18 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_units(t_dict *dict, char *nb, int digits)
{
	char	*r;

	if (digits == 1)
	{
		r = ft_map_search(dict, nb, 1, 1);
		ft_putstr(r);
		return ;
	}
	if (nb[0] != '0')
	{
		ft_putstr(" ");
		r = ft_map_search(dict, nb, 1, 1);
		ft_putstr(r);
	}
}

void	print_tens(t_dict *dict, char *nb, int digits)
{
	char	*r;

	if (nb[0] == '0')
	{
		nb++;
		print_units(dict, nb, digits);
		return ;
	}
	if (digits == 3)
		ft_putstr(" ");
	if (nb[0] == '1')
	{
		r = ft_map_search(dict, nb, 2, 2);
		ft_putstr(r);
	}
	else
	{
		r = ft_map_search(dict, nb, 2, 1);
		ft_putstr(r);
		nb++;
		print_units(dict, nb, digits);
	}
}

void	print_hundreds(t_dict *dict, char *nb, int digits)
{
	char	*hd;
	char	*r;

	if (nb[0] == '0')
	{
		nb++;
		print_tens(dict, nb, digits);
		return ;
	}
	r = ft_map_search(dict, nb, 1, 1);
	hd = ft_map_search2(dict, 3);
	ft_putstr(r);
	ft_putstr(" ");
	ft_putstr(hd);
	nb++;
	print_tens(dict, nb, digits);
}
