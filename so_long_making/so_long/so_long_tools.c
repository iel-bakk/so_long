/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:48:49 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:11:21 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *str, t_long_data *data, int zero)
{
	int	i;

	i = 0;
	if (!compare_line_len(data->x, str) || data->x < 3)
	{
		free(str);
		found_error();
	}
	while (str[i])
	{
		zero += (str[i] == '0');
		if (!compare_char(str[0], '1') || !compare_char(str[data->x - 1], '1'))
		{
			free(str);
			found_error();
		}
		else if (!collect_map_objects(str[i], data))
		{
			free(str);
			found_error();
		}
		i++;
	}
	zero_check(zero, str);
}

void	zero_check(int zero, char *str)
{
	if (!zero)
	{
		free(str);
		found_error();
	}
}
