/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:38:32 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 18:26:32 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i != len)
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	if (!(cpy = (char *)malloc(sizeof(char) * ((len - i) + 1))))
		return (NULL);
	while (j + i < len)
	{
		cpy[j] = s[i + j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
