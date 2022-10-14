/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:18:22 by obelaizi          #+#    #+#             */
/*   Updated: 2022/07/31 19:25:51 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *s, char *to_find)
{
	int	j;
	int	h;

	h = 0;
	j = 0;
	while (to_find[j] != '\0')
	{
		if (s[j] == to_find[j])
			h++;
		j++;
	}
	if (h == j)
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	s;

	if (to_find[0] == '\0')
		return (str);
	if (str[0] == '\0')
		return (0);
	s = 0;
	while (*str)
	{
		if (str[0] == to_find[0])
			if (check(str, to_find) == 0)
				return (str);
		str++;
	}
	return (0);
}
