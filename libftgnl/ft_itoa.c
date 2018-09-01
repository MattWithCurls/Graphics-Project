/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:25:26 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 18:27:09 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./includes/libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = -1;
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (ft_isneg(n) % 10) + '0';
		n = ft_isneg(n) / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
