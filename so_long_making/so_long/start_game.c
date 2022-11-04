/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:02:12 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:06:49 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_the_game(t_long_data *data, t_content *mc)
{
	initialize_map_struct(mc);
	mc->data = data;
	mc->mlx = mlx_init();
	if (!mc->mlx)
	{
		free_map(data);
		found_error();
	}
	mc->mlx_win = mlx_new_window(mc->mlx, data->x * 64, data->y * 64, "test");
	if (!mc->mlx_win)
	{
		free_map(data);
		found_error();
	}
	get_elements_addr(mc, data);
	get_player_position(mc);
	print_map(data, mc);
	mlx_key_hook (mc->mlx_win, mouvement, mc);
	mlx_hook(mc->mlx_win, 17, 0, exit_n_free, mc);
	mlx_loop(mc->mlx);
}

void	player_up(t_content *mc)
{
	mc->move++;
	write(1, "move : ", 7);
	ft_putnbr(mc->move);
	write(1, "\n", 1);
	mlx_clear_window(mc->mlx, mc->mlx_win);
	if (mc->data->map[mc->py - 1][mc->px] == 'C')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py - 1][mc->px] = 'P';
		mc->py--;
		mc->data->collect--;
	}
	else if (mc->data->map[mc->py - 1][mc->px] == '0')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py - 1][mc->px] = 'P';
		mc->py--;
	}
	else if (mc->data->map[mc->py - 1][mc->px] == 'E' && !mc->data->collect)
		exit_n_free(mc);
}

void	player_left(t_content *mc)
{
	mc->move++;
	write(1, "move : ", 7);
	ft_putnbr(mc->move);
	write(1, "\n", 1);
	mlx_clear_window(mc->mlx, mc->mlx_win);
	if (mc->data->map[mc->py][mc->px - 1] == 'C')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py][mc->px - 1] = 'P';
		mc->px--;
		mc->data->collect--;
	}
	else if (mc->data->map[mc->py][mc->px - 1] == '0')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py][mc->px - 1] = 'P';
		mc->px--;
	}
	else if (mc->data->map[mc->py][mc->px - 1] == 'E' && !mc->data->collect)
		exit_n_free(mc);
}

void	player_right(t_content *mc)
{
	mc->move++;
	write(1, "move : ", 7);
	ft_putnbr(mc->move);
	write(1, "\n", 1);
	mlx_clear_window(mc->mlx, mc->mlx_win);
	if (mc->data->map[mc->py][mc->px + 1] == 'C')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py][mc->px + 1] = 'P';
		mc->px++;
		mc->data->collect--;
	}
	else if (mc->data->map[mc->py][mc->px + 1] == '0')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py][mc->px + 1] = 'P';
		mc->px++;
	}
	else if (mc->data->map[mc->py][mc->px + 1] == 'E' && !mc->data->collect)
		exit_n_free(mc);
}

void	player_down(t_content *mc)
{
	mc->move++;
	write(1, "move : ", 7);
	ft_putnbr(mc->move);
	write(1, "\n", 1);
	mlx_clear_window(mc->mlx, mc->mlx_win);
	if (mc->data->map[mc->py + 1][mc->px] == 'C')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py + 1][mc->px] = 'P';
		mc->py++;
		mc->data->collect--;
	}
	else if (mc->data->map[mc->py + 1][mc->px] == '0')
	{
		mc->data->map[mc->py][mc->px] = '0';
		mc->data->map[mc->py + 1][mc->px] = 'P';
		mc->py++;
	}
	else if (mc->data->map[mc->py + 1][mc->px] == 'E' && !mc->data->collect)
		exit_n_free(mc);
}
