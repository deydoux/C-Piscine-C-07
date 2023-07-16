/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:08:55 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/16 07:53:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

char	**init_strs(char *str, char *charset)
{
	int		i;
	int		size;
	char	**strs;

	if (!str[0])
		return (NULL);
	i = 1;
	size = 1;
	while (str[i])
	{
		if (contains(charset, str[i]) && !contains(charset, str[i - 1])
			&& str[i + 1] != 0)
			size++;
		i++;
	}
	strs = malloc(sizeof(char *) * size + 1);
	if (!strs)
		return (NULL);
	strs[size] = 0;
	return (strs);
}

char	*segment(char *src, char *charset, int *i)
{
	int		size;
	char	*str;
	int		j;

	while (contains(charset, src[*i]))
		(*i)++;
	size = 0;
	while (src[*i + size] && !contains(charset, src[*i + size]))
		size++;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (str[j])
		str[j++] = src[(*i)++];
	str[size - 1] = 0;
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;

	strs = init_strs(str, charset);
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (strs[i])
		strs[i++] = segment(str, charset, &j);
	return (strs);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(void)
{
	char	**strs = ft_split("Hello, World !", " ");

	ft_putstr(strs[1]);
}
