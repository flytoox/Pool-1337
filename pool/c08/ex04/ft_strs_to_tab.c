/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:40:47 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/11 20:40:49 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*cp;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	cp = malloc((i + 1) * sizeof(char));
	while (i)
	{
		cp[j] = src[j];
		j++;
		i--;
	}
	cp[j] = 0;
	return (cp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str	*arr;

	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_str_length(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
