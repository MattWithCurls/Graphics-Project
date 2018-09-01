/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:27:30 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 18:19:31 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (s2 < s1)
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	else
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (s1);
}
