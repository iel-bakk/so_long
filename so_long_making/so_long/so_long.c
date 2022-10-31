/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:46:22 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/10/30 02:52:42 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_long_data	data;

	if (ac == 2)
	{
		check_map_name(av[1]);
		initialize_struct(&data);
		data.file_name = av[1];
		is_map_valid(&data);
	}
	return (0);
}