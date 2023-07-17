/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:13:15 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/17 13:19:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

void	ft_rev_str(char *str, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		tmp_nbr;
	int		size;
	char	*str;

	tmp_nbr = nbr;
	size = 0;
	while (tmp_nbr)
	{
		tmp_nbr /= ft_strlen(base);
		size++;
	}
	str = malloc(sizeof(char) * (size + 2));
	tmp_nbr = nbr;
	size = 0;
	while (tmp_nbr)
	{
		str[size++] = base[ft_abs(tmp_nbr % ft_strlen(base))];
		tmp_nbr /= ft_strlen(base);
	}
	if (nbr < 0)
		str[size++] = '-';
	str[size] = 0;
	ft_rev_str(str, size);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (check_base(base_from) || check_base(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
