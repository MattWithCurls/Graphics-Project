/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:33:45 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 18:19:56 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (dst[len] && len < dstsize)
		len++;
	while (src[i] != '\0' && len + i + 1 < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len != dstsize)
		dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
