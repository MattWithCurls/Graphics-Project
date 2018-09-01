/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:42:56 by msteer            #+#    #+#             */
/*   Updated: 2018/09/01 16:59:43 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libftgnl/includes/libft.h"
#include "../libftgnl/get_next_line.h"

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			row_count;
	int			col_count;
	int			**int_map;
	char		**split;
}				t_map;

typedef struct s_line
{
	float x1;
	float y1;
	float x2;
	float y2;
	
}				t_line;

void	mapmem(t_map *map, int fd);
void    r_map(char *file, t_map *map, int fd);
void	print_map(t_map *map);
void	calc_col_line(t_map *map, int j, int i);
void	calc_row_line(t_map *map, int j, int i);
#endif
