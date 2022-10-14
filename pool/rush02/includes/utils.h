/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:39:17 by obelaizi          #+#    #+#             */
/*   Updated: 2022/08/07 16:49:39 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_numbers
{
	char	*key;
	int		digits;
	char	*value;
}	t_dict;

char	**ft_split(char *str, char *charset);
int		ft_strlen(char	*s);
int		spaces(char c);
char	*ft_strdup(char *src);
int		ft_atoi(char *str);
t_dict	*ft_map(char **dict, int size);
void	ft_show_tab(t_dict *nb);
int		ft_dict_size(t_dict *dict);
char	*ft_map_search(t_dict *dict, char *nb, int digits, int n);
char	*ft_map_search2(t_dict *dict, int digits);
void	ft_putstr(char *str);
void	print_number(t_dict *dict, char *nb);
void	print_units(t_dict *dict, char *nb, int digits);
void	print_tens(t_dict *dict, char *nb, int digits);
void	print_hundreds(t_dict *dict, char *nb, int digits);

#endif
