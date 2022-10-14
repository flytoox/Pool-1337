/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:47:07 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/09 17:47:10 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	j;
	int	*t;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	t = malloc(size * sizeof(int));
	j = min;
	i = 0;
	while (i < size)
	{
		t[i] = j;
		j++;
		i++;
	}
	return (t);
}
