/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:26:56 by msteer            #+#    #+#             */
/*   Updated: 2018/07/01 15:26:58 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	i = 0;
	ds = (char *)dst;
	sr = (char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
