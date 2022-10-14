/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:19 by obelaizi          #+#    #+#             */
/*   Updated: 2022/10/09 21:03:36 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	i;
	unsigned int	j;
	unsigned int	h;

	s = 0;
	i = 0;
	j = 0;
	while (dest[s] != '\0')
		s++;
	while (src[j] != '\0')
		j++;
	if (size <= s)
		return (j + size);
	h = s;
	while (src[i] != '\0' && i < size - h - 1)
	{
		dest[s] = src[i];
		s++;
		i++;
	}
	dest[s] = 0;
	return (j + h);
}
