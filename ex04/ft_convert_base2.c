/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:07:27 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/17 13:20:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	index_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len] != '\0')
	{
		if (index_of(base[len], "+- \f\n\r\t\v") != -1)
			return (1);
		i = len;
		while (base[++i] != '\0')
			if (base[len] == base[i])
				return (1);
		len++;
	}
	return (len <= 1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;
	int	base_len;

	i = 0;
	while (index_of(str[i], " \f\n\r\t\v") != -1)
		i++;
	sign = 1;
	while (index_of(str[i], "+-") != -1)
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	n = 0;
	base_len = ft_strlen(base);
	while (index_of(str[i], base) != -1)
		n = n * base_len + index_of(str[i++], base);
	return (sign * n);
}
