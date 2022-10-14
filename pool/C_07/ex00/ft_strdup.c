/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:40:49 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/09 17:46:42 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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
