/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:14:50 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/03 09:37:29 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	j;
	int	s;
	int	ss;

	s = 0;
	while (s1[s] != '\0')
		s++;
	ss = 0;
	while (s2[ss] != '\0')
		ss++;
	j = 0;
	while (s1[j] != '\0' && s1[j] == s2[j])
		j++;
	return (s1[j] - s2[j]);
}

void	sort(int size, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	sort(ac, av);
	i = 1;
	while (ac > 1)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
		ac--;
	}
}
