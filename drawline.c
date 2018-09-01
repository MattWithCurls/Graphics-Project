/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:08:20 by msteer            #+#    #+#             */
/*   Updated: 2018/09/01 17:09:09 by msteer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include "mlx.h"
#include<stdlib.h>
#include <math.h>

void	drawline(t_map *map, t_line *line)
{
	float x, y, dx, dy, step;
	int i;
   	
	dx = (line->x2 - line->x1);
	dy = (line->y2 - line->y1);
	if(fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = line->x1;
	y = line->y1;
	i = 1;
	while(i <= step) 
	{
		mlx_pixel_put(map->mlx, map->win, x, y, 0x0FFFF);
		x = x + dx;
		y = y + dy;
		i = i + 1;
		//delay(100);
	}
	//getch();
	//closegraph();
}

void	calc_row_line(t_map *map, int j, int i)
{
	t_line		line;

	line.x1 = (j + i) * (10 / tan(30 * 0.0174533)) + 100;
	line.y1 = (i - j) * 10 - 10 * map->int_map[i][j]
		+ 900;
	line.x2 = (j + i + 1) * (10 / tan(30 * 0.0174533)) + 100;
	line.y2 = (i - j + 1) * 10 - 10 * map->int_map[i + 1][j]
		 + 900;
	drawline(map, &line);
}

void	calc_col_line(t_map *map, int j, int i)
{
	t_line		line;

	line.x1 = (j + i) * (10 / tan(30 * 0.0174533)) + 100;
	line.y1 = (i - j) * 10 - 10 * map->int_map[i][j] 
	   	+ 900;
	line.x2 = (j + i + 1) * (10 / tan(30 * 0.0174533)) + 100;
   	line.y2 = (i - j - 1) * 10 - 10 * map->int_map[i][j + 1] 
		+ 900;
	drawline(map, &line);
}	

int	key_hook(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

/*int	main()
{
	void *mlx;
	void *win;
	int	map [11][19] =
	{
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0,  0,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10, 0,  0,  0, 10,10, 10, 10, 10,  0,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0},
		{0,  0, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0, 10, 10, 10, 10,  0,  0,  0},
		{0,  0,  0, 10, 10, 10, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0, 0,  10, 10,  0,  0,  0, 10, 10, 10, 10, 10, 10,  0,  0},
		{0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{0,  0,  0,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
	};
	t_line	line1, line2, line3;

	line1.x1 = 100;
	line1.y1 = 100;
	line1.x2 = 200;
	line1.y2 = 300;
	line2.x1 = 100;
	line2.y1 = 100;
	line2.x2 = 200;
	line2.y2 = 350;
	line3.x1 = 200;
	line3.y1 = 300;
	line3.x2 = 200;
	line3.y2 = 750;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2560, 1315, "fdf");
	drawline(win, mlx, &line1);
	drawline(win, mlx, &line2);
	drawline(win, mlx, &line3);
	mlx_key_hook(win,key_hook, 0);
	mlx_loop(mlx);
}*/
