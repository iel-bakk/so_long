/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_file_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:10:43 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:11:11 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_other_char(t_long_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'C')
				if (data->map[i][j] != 'P')
					if (data->map[i][j] != 'E')
						if (data->map[i][j] != '0')
							if (data->map[i][j] != '1')
								if (data->map[i][j] != '\n')
									return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	collect_map_objects(char collect_me, t_long_data *data)
{
	if (collect_me == 'P')
	{
		if (data->player)
			return (0);
		else
			data->player++;
	}
	else if (collect_me == 'E')
	{
		if (data->exit)
			return (0);
		else
			data->exit++;
	}
	else if (collect_me == 'C')
		data->collect++;
	else if (collect_me == '0' || collect_me == '1')
		return (1);
	return (1);
}

void	check_wall(char *str, t_long_data *data)
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
		if (str[i] == '\n' && str[i + 1] == '\0')
			break ;
		if (!compare_char(str[i], '1'))
		{
			free(str);
			found_error();
		}
		i++;
	}
}

void	check_the_storage(t_long_data *data)
{
	if (data->player != 1)
	{
		free_map(data);
		found_error();
	}
	if (!data->collect)
	{
		free_map(data);
		found_error();
	}
	if (data->exit != 1)
	{
		free_map(data);
		found_error();
	}
}

void	free_map(t_long_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = data->map[i];
	while (str)
	{
		free(str);
		str = data->map[++i];
	}
	free(data->map);
}
