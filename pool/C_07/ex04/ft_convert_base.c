/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:41:52 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/11 13:41:55 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	good(char *base);

int	count(int nbr, int size, int lenght)
{
	int	nb;

	if (nbr < 0)
	{
		nb = nbr * -1;
		lenght++;
	}
	else
		nb = nbr;
	while (nb >= size)
	{
		nb /= size;
		lenght++;
	}
	lenght++;
	return (lenght);
}

void	helper(int nbr, char *base, int size, char *str)
{
	int	lenght;
	int	i;

	lenght = count(nbr, size, 0);
	i = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
		i = 1;
	}
	lenght--;
	while (nbr >= size)
	{
		str[lenght] = base[nbr % size];
		nbr /= size;
		lenght--;
	}
	if (nbr < size)
		str[i] = base[nbr];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size;
	int		n;
	int		lenght;
	char	*str;

	if (good(base_to) == 0 || good(base_from) == 0)
		return (0);
	n = ft_atoi_base(nbr, base_from);
	size = good(base_to);
	lenght = count(n, size, 0);
	str = malloc((lenght + 1) * sizeof(char));
	if (!str)
		return (0);
	helper(n, base_to, size, str);
	str[lenght] = 0;
	return (str);
}
