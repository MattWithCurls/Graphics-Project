/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:35:03 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 18:23:49 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	int				i;
	int				len;
	char			*str;

	k = 0;
	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f(k, s[i]);
			k++;
			i++;
		}
		return (str);
	}
	return (NULL);
}
