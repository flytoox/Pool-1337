/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:33:43 by obelaizi          #+#    #+#             */
/*   Updated: 2022/07/29 13:21:26 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				s;
	unsigned int	j;

	s = 0;
	j = 0;
	while (dest[s] != '\0')
		s++;
	while (src[j] != '\0' && j < nb)
	{
		dest[s] = src[j];
		j++;
		s++;
	}
	dest[s] = '\0';
	return (dest);
}
