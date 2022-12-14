/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:27:59 by obelaizi          #+#    #+#             */
/*   Updated: 2022/07/23 00:43:52 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	x1;
	char	x2;
	char	x3;

	x1 = '0';
	while (x1 <= '7')
	{
		x2 = x1 + 1;
		while (x2 <= '9')
		{
			x3 = x2 + 1;
			while (x3 <= '9')
			{
				write(1, &x1, 1);
				write(1, &x2, 1);
				write(1, &x3, 1);
				if (x1 != '7' )
					write(1, ", ", 2);
				x3++;
			}
		x2++;
		}
	x1++;
	}
}
