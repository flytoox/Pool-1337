/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:41:07 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/02 18:46:16 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	good(char *base)
{
	int	i;
	int	j;

	if (base[1] == 0 || base[0] == 0)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	helper(unsigned int nbr, char *base, unsigned int i)
{
	if (nbr < i)
		write(1, &(base[nbr]), 1);
	else
	{
		helper(nbr / i, base, i);
		helper(nbr % i, base, i);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	n;

	n = nbr;
	if (good(base) == 0)
		return ;
	i = good(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -nbr;
	}
	else
		n = nbr;
	helper(n, base, i);
}
