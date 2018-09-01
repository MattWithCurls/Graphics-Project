/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:11:30 by msteer            #+#    #+#             */
/*   Updated: 2018/08/18 20:03:05 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#include <unistd.h>
#include "includes/libft.h"

#define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);
#	endif
