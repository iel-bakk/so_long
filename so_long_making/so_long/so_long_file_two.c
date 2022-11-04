/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_file_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:09:45 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:09:51 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare_line_len(int len, char *str)
{
	int	l;

	l = ft_strlen(str);
	if (str[l - 1] == '\n')
		l--;
	return (len == l);
}

int	map_len(int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		found_error();
	while (tmp)
	{
		++len;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (len);
}

void	found_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// first char and the last char need to be 1

void	initialize_struct(t_long_data *data)
{
	data->map = NULL;
	data->file_name = NULL;
	data->collect = 0;
	data->exit = 0;
	data->player = 0;
	data->x = 0;
	data->y = 0;
	data->lines_total = 0;
}

void	get_player_position(t_content *mc)
{
	while (mc->py < mc->data->y)
	{
		mc->px = 0;
		while (mc->px < mc->data->x)
		{
			if (mc->data->map[mc->py][mc->px] == 'P')
				return ;
			mc->px++;
		}
		mc->py++;
	}
}
