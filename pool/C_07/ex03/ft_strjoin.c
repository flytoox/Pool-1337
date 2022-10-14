/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:51:40 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/11 15:37:03 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size_tab(int size, char **strs, char *sep)
{
	int	l;
	int	i;

	l = 1;
	i = 0;
	while (i < size)
		l = l + (ft_strlen(strs[i++]) + ft_strlen(sep)) * (size - 1);
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		j;
	int		m;

	m = 0;
	i = 0;
	res = malloc((size_tab(size, strs, sep) + 1) * sizeof(char));
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[m++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			res[m++] = sep[j++];
		i++;
	}
	res[m] = 0;
	return (res);
}
