/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:32:06 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 16:36:32 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include "utils.h"

int	spaces(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putsize(int size)
{
	char	c;

	if (size > 9)
		ft_putsize(size / 10);
	c = size % 10 + 48;
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, (str + i), 1);
		i++;
	}
}

int	ft_dict_size(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict->digits != -1)
	{
		i++;
		dict++;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1)
			return (0);
		i++;
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_map_search2(t_dict *dict, int digits)
{
	while (dict->digits != -1)
	{
		if (digits == dict->digits)
			return (dict->value);
		dict++;
	}
	return (dict->value);
}

char	*ft_map_search(t_dict *dict, char *nb, int digits, int n)
{
	while (dict->digits != -1)
	{
		if (digits == dict->digits)
		{
			if (ft_strncmp(dict->key, nb, n) == 0)
				return (dict->value);
		}
		dict++;
	}
	return (dict->value);
}
