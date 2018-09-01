/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:37:54 by msteer            #+#    #+#             */
/*   Updated: 2018/07/01 15:37:55 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (to_find[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
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
