/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:06:52 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 14:07:41 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(char *str, int i, int sign)
{
	int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

int	white_space(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\r'
		|| c == '\f' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (white_space(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] == '+')
		{
			i++;
			continue ;
		}
		else
			break ;
		i++;
	}
	return (solve(str, i, sign));
}
