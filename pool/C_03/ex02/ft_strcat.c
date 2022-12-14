/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:14:48 by obelaizi          #+#    #+#             */
/*   Updated: 2022/07/28 17:32:57 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	s;
	int	j;

	s = 0;
	j = 0;
	while (dest[s] != '\0')
		s++;
	while (src[j] != '\0')
	{
		dest[s] = src[j];
		j++;
		s++;
	}
	dest[s] = '\0';
	return (dest);
}	
