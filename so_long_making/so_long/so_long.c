/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:46:22 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/01 05:37:46 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <mlx.h>

int main(int ac, char **av)
{
	t_long_data	data;
	// int			i = 0;

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
		// printf("x = %d\ny = %d\nplayer = %d\ncollect = %d\nexit = %d\n", data.x, data.y, data.player, data.collect, data.exit);
		// while (data.map[i])
		// 	printf("%s\n", data.map[i++]);
		void	*mlx;
		void	*mlx_win;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, data.x * 64, data.y * 64, "so_long kol khir ystahlo jesus");
		mlx_loop(mlx);
	}
	else
		found_error();
	return (0);
}