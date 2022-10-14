/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:37:54 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/02 19:01:27 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	index_of(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\r' || c == '\n'
		|| c == '\f' || c == '\v');
}

int	good(char *base)
{
	int	i;
	int	j;

	if (base[1] == 0 || base[0] == 0)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || is_whitespace(base[i]))
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

int	ft_atoi_base(char *str, char *base)
{
	int	g;
	int	result;
	int	sign;
	int	i;

	if (good(base) == 0)
		return (0);
	g = good(base);
	while (*str <= 32)
		str++;
	sign = 1;
	result = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (index_of(*str, base) != -1 && *str)
	{
		i = index_of(*str, base);
		result = result * g + i;
		str++;
	}
	return (result * sign);
}
