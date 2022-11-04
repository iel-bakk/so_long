/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:00:16 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:00:37 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_elements_addr(t_content *mc, t_long_data *data)
{
	data->lines_total++;
	mc->player = mlx_xpm_file_to_image(mc->mlx, "./items/player.xpm",
			&mc->width, &mc->height);
	mc->wall = mlx_xpm_file_to_image(mc->mlx, "./items/brik.xpm",
			&mc->width, &mc->height);
	mc->collect = mlx_xpm_file_to_image(mc->mlx, "./items/collect.xpm",
			&mc->width, &mc->height);
	mc->exit = mlx_xpm_file_to_image(mc->mlx, "./items/door.xpm",
			&mc->width, &mc->height);
	mc->empty = mlx_xpm_file_to_image(mc->mlx, "./items/floor.xpm",
			&mc->width, &mc->height);
	if (!mc->player || !mc->collect || !mc->empty || !mc->exit || !mc->wall)
	{
		free_map(data);
		found_error();
	}
}

void	ft_putnbr(int move)
{
	char	c;

	if (move < 10)
	{
		c = move + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(move / 10);
		ft_putnbr(move % 10);
	}
}

void	print_element(char c, t_content *mc)
{
	if (c == '0')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win,
			mc->empty, mc->x * 64, mc->y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win,
			mc->player, mc->x * 64, mc->y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win,
			mc->exit, mc->x * 64, mc->y * 64);
	else if (c == '1')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win,
			mc->wall, mc->x * 64, mc->y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(mc->mlx, mc->mlx_win,
			mc->collect, mc->x * 64, mc->y * 64);
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
	mc->mlx = NULL;
	mc->mlx_win = NULL;
	mc->player = NULL;
	mc->wall = NULL;
	mc->x = 0;
	mc->y = 0;
	mc->height = 64;
	mc->width = 64;
	mc->data = NULL;
	mc->px = 0;
	mc->py = 0;
	mc->move = 0;
}
