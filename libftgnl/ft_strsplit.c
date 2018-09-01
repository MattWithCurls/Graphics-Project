/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:37:40 by msteer            #+#    #+#             */
/*   Updated: 2018/08/20 09:16:58 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./includes/libft.h"

/*int    ft_getwcntsd(char const *s, char c)
{
    int res;

    res = 0;
    while (*s)
    {
        if (*s != c)
        {
            while (*s != c && *s)
                s++;
            res++;
        }
        else
            s++;
    }
    if (res == 0)
        return (1);
    return (res);
}*/

/*char    **ft_strsplit(char const *s, char c)
{
    char    **ret;
    int        i;
    int        j;
    size_t    w_count;

    if (!s || !(ret = (char**)malloc(sizeof(char*) * (ft_getwcntsd(s, c) + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            w_count = 0;
            while (s[i + (int)w_count] && (s[i + (int)w_count] != c))
                w_count++;
            if (!(ret[j++] = ft_strsub(s, i, w_count)))
                return (NULL);
            i = i + (int)w_count;
        }
    }
    ret[j] = (NULL);
    return (ret);
}*/

int	ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	word(char const *str, char c)
{
	int	a;
	int	l;

	a = 0;
	l = 0;
	while (str[a] == c)
		a++;
	while (str[a] != c && str[a] != '\0')
	{
		a++;
		l++;
	}
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	x = -1;
	y = 0;
	while (++x < ft_countwords(s, c))
	{
		z = 0;
		if (!(str2[x] = ft_strnew(word(&s[y], c) + 1)))
			str2[x] = NULL;
		while (s[y] == c)
			y++;
		while (s[y] != c && s[y])
			str2[x][z++] = s[y++];
		str2[x][z] = '\0';
	}
	str2[x] = 0;
	return (str2);
}
