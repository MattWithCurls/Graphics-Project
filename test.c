
#include "includes/header.h"
#include <stdio.h>
#include <fcntl.h>    
#include <stdlib.h>
#include "libftgnl/get_next_line.h"


void		mapmem(t_map *map, int fd)
{
	int		i;
	int 	j;
	char 	*buff;
	char	**temp;

	i = 0;
	j = 0;
	map->split = (char **)malloc(sizeof(char *) * (map->row_count + 1));
	while (get_next_line(fd, &buff) > 0)
	{
		map->split[i] = ft_strdup(buff);
		ft_strdel(&buff);
		i++;
	}
	temp = ft_strsplit(map->split[0], ' ');
	while (temp[j])
		j++;
	map->col_count = j;
	j = 0;
	map->int_map = (int **)ft_memalloc(sizeof(int *) * map->row_count);
	while(j < map->row_count)
	{
		map->int_map[j] = (int *)malloc(sizeof(int) * map->col_count);
		j++;
	}
}

void		r_map(char *file, t_map *map, int fd)
{
	int	i;
	int j;
	char *buff;
	char	**temp;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (0 < get_next_line(fd, &buff))
		i++;
	map->row_count = i;
	close(fd);
	fd = open(file, O_RDONLY);
	mapmem(map, fd);
	i = 0;
	while (i < map->row_count)
	{
		temp = ft_strsplit(map->split[i], ' ');
		j = 0;
		while(j <  map->col_count)
		{
			map->int_map[i][j] = ft_atoi(temp[j]);
			j++;
		}
		while (j >= 1)
			ft_strdel(&temp[--j]);
		i++;
	}
}

int			press(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

void	print_map(t_map *map)
{
	int i = 0;
	int j = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->col_count)
		{
			if (j < map->col_count - 1)
				calc_col_line(map, j, i);

			if (i < map->row_count - 1)
				calc_row_line(map, j, i);
			j++;
		}
		i++;
	}
}
	


int        main(int argc, char **argv)
{
    int    	i;
    int		j;
	int		fd;
    t_map 	*map;

	i = 0;
	j =  0;
	fd = 0;
	map = (t_map *)malloc(sizeof(t_map));
    if (argc == 2)
    {
		map->mlx = mlx_init();
		map->win = mlx_new_window(map->mlx, 2560, 1440, argv[1]);
        r_map(argv[1], map, fd);
		/*while (j < map->row_count)
		{
			i = 0;
			while (i < map->col_count)
			{
				printf("%d", map->int_map[j][i]);
				i++;
			}
				printf("\n");
			j++;
		}*/
		print_map(map);
		mlx_key_hook(map->win, press, 0);
		mlx_loop(map->mlx);
    }
    return (0);
}
