/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:46:22 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/03 06:02:38 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_elements_addr(t_content *mc, t_long_data *data)
{
	data->lines_total++;
	mc->player = mlx_xpm_file_to_image(mc->mlx, "./items/player.xpm", &mc->width, &mc->height);
	mc->wall = mlx_xpm_file_to_image(mc->mlx, "./items/brik.xpm", &mc->width, &mc->height);
	mc->collect = mlx_xpm_file_to_image(mc->mlx, "./items/collect.xpm", &mc->width, &mc->height);
	mc->exit = mlx_xpm_file_to_image(mc->mlx, "./items/door.xpm", &mc->width, &mc->height);
	mc->empty = mlx_xpm_file_to_image(mc->mlx, "./items/floor.xpm", &mc->width, &mc->height);
	if (!mc->player || !mc->collect || !mc->empty || !mc->exit || !mc->wall)
	{
		free_map(data);
		found_error();
	}
}

void	print_element(char c, t_content *mc)
{
	if (c == '0')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win, mc->empty, mc->x * 64, mc->y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win, mc->player, mc->x * 64, mc->y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win, mc->exit, mc->x * 64, mc->y * 64);
	else if (c == '1')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win, mc->wall, mc->x * 64, mc->y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win, mc->collect, mc->x * 64, mc->y * 64);
}

void	print_map(t_long_data *data, t_content *mc)
{
	mc->y = 0;
	while (mc->y < data->y)
	{
		mc->x = 0;
		while (mc->x < data->x)
		{
			print_element(data->map[mc->y][mc->x], mc);
			mc->x++;
		}
		mc->y++;
	}
}

void	initialize_map_struct(t_content *mc)
{
	mc->collect = NULL;
	mc->empty = NULL;
	mc->exit = NULL;
	mc->img = NULL;
	mc->mlx = NULL;
	mc->mlx_win = NULL;
	mc->player = NULL;
	mc->wall = NULL;
	mc->x = 0;
	mc->y = 0;
	mc->height = 64;
	mc->width = 64;
	mc->data = NULL;
	mc->p->x = 0;
	mc->p->y = 0;
}

void	start_the_game(t_long_data *data)
{
	t_content mc;

	initialize_map_struct(&mc);
	mc.data = data;
	mc.mlx = mlx_init();
	if (!mc.mlx)
	{
		free_map(data);
		found_error();
	}
	mc.mlx_win = mlx_new_window(mc.mlx, data->x * 64, data->y * 64, "test");
	mc.img = mlx_new_image(mc.mlx, data->x * 64, data->y * 64);
	if (!mc.img || !mc.mlx_win)
	{
		free_map(data);
		found_error();
	}
	get_elements_addr(&mc, data);
	get_player_position(&mc);
	printf("player x = %d player y = %d\n", mc.p->x, mc.p->y);
	print_map(data, &mc);
	mlx_loop(mc.mlx);
}

int main(int ac, char **av)
{
	t_long_data	data;

	if (ac == 2)
	{
		check_map_name(av[1]);
		initialize_struct(&data);
		data.file_name = av[1];
		is_map_valid(&data);
		check_the_storage(&data);
		if (check_other_char(&data) == 0)
		{
			free_map(&data);
			found_error();
		}
		printf("%d\n %d\n", data.x, data.y);
		start_the_game(&data);
	}
	else
		found_error();
	return (0);
}