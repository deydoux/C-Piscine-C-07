/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:13:15 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/16 19:20:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (check_base(base_from) || check_base(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
