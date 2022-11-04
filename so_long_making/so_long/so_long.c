/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:46:22 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:03:31 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouvement(int key_value, t_content *mc)
{
	if (key_value == KEY_W)
		player_up(mc);
	if (key_value == KEY_A)
		player_left(mc);
	if (key_value == KEY_D)
		player_right(mc);
	if (key_value == KEY_S)
		player_down(mc);
	if (key_value == ESC_KEY)
		exit_n_free(mc);
	print_map(mc->data, mc);
	return (0);
}

int	exit_n_free(t_content *mc)
{
	free_map(mc->data);
	mlx_clear_window(mc->mlx, mc->mlx_win);
	mlx_destroy_window(mc->mlx, mc->mlx_win);
	write(1, "Bye\n", 4);
	exit(0);
	return (1);
}

int	main(int ac, char **av)
{
	t_long_data	data;
	t_content	mc;

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
		start_the_game(&data, &mc);
	}
	else
		found_error();
	return (0);
}
