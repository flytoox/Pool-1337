/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:10:03 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/11 01:11:38 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	spaces(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	length(char *str, char *charset)
{
	int	total;
	int	first;

	total = 0;
	while (*str)
	{
		first = 1;
		while (spaces(*str, charset))
			str++;
		while (!spaces(*str, charset) && *str)
		{
			if (first == 1)
				total++;
			first = 0;
			str++;
		}
	}
	return (total);
}

int	size_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!spaces(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*word(char **str, char *charset)
{
	char	*s;
	int		j;

	j = 0;
	s = malloc((size_word(*str, charset) + 1) * sizeof(char));
	while (!spaces(**str, charset) && **str)
	{
		s[j] = **str;
		++*str;
		j++;
	}
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		size;
	char	**sp;
	int		w;

	size = length(str, charset);
	sp = malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (spaces(*str, charset))
			str++;
		w = size_word(str, charset);
		sp[i] = malloc((w + 1) * sizeof(char));
		sp[i] = word(&str, charset);
		sp[i][w] = '\0';
		i++;
	}
	sp[i] = 0;
	return (sp);
}
