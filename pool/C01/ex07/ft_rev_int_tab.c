/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:53:11 by obelaizi          #+#    #+#             */
/*   Updated: 2022/07/25 12:23:22 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	if (size == 0)
		return ;
	i = 0;
	k = size - 1;
	size--;
	while (i <= (k / 2))
	{
		j = tab[size];
		tab[size] = tab[i];
		tab[i] = j;
		size--;
		i++;
	}
}
