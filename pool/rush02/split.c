/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:08:03 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 14:08:24 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	first_word;
	int	total;

	total = 0;
	while (*str)
	{
		first_word = 1;
		while (is_separator(*str, charset) && *str)
			str++;
		while (!is_separator(*str, charset) && *str)
		{
			if (first_word == 1)
			{
				total++;
				first_word = 0;
			}
			str++;
		}
	}
	return (total);
}

char	*extract_string(char *str, char *charset)
{
	while (is_separator(*str, charset) && *str)
		str++;
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		length;
	int		j;
	int		size;

	size = count_strings(str, charset) + 1;
	result = malloc(sizeof(result) * size);
	i = 0;
	while (i < size - 1)
	{
		length = 0;
		j = -1;
		str = extract_string(str, charset);
		while (!is_separator(str[length], charset) && str[length])
			length++;
		result[i] = malloc(sizeof(result[i]) * (length + 1));
		while (++j < length)
			result[i][j] = str[j];
		result[i][j] = 0;
		str = str + length;
		i++;
	}
	result[i] = 0;
	return (result);
}
