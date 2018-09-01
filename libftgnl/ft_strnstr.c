/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:36:43 by msteer            #+#    #+#             */
/*   Updated: 2018/07/01 15:36:45 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	int				j;
	int				size;

	i = 0;
	j = 0;
	size = 0;
	while (to_find[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (to_find[j] == str[i + j] && i + j < len)
		{
			if (j == size - 1)
				return ((char *)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
