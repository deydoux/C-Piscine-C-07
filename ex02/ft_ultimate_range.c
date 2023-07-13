/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:28:50 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/13 18:24:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
		return (-1);
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
		(*range)[i++] = min++;
	return (size);
}
