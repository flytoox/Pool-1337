/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:08:56 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 14:16:43 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "utils.h"

char	*get_key(char *str)
{
	char	*nb;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (!spaces(str[size]) && str[size])
		size++;
	--size;
	nb = malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		nb[i] = str[i];
		i++;
	}
	nb[i] = 0;
	return (nb);
}

char	*get_value(char *str)
{
	char	*val;
	int		i;
	int		j;
	int		length;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	i++;
	while (spaces(str[i]) && str[i])
		i++;
	length = 0;
	while (str[length] && str[length] != '\n' && !spaces(str[i]))
		length++;
	val = malloc(sizeof(char) * (length + 1));
	j = 0;
	while (j < length)
	{
		val[j] = str[i + j];
		j++;
	}
	val[j] = 0;
	return (val);
}

t_dict	*ft_map(char **dict, int size)
{
	t_dict		*numbers;
	int			i;

	numbers = malloc(sizeof(*numbers) * (size + 1));
	if (numbers == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		numbers[i].key = get_key(dict[i]);
		numbers[i].digits = ft_strlen(numbers[i].key);
		numbers[i].value = get_value(dict[i]);
		i++;
	}
	numbers[i].digits = -1;
	return (numbers);
}
