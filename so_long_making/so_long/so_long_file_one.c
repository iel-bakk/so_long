/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_file_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:08:34 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:08:35 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare_char(char a, char b)
{
	return (a == b);
}

void	check_map_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!compare_char(str[--len], 'r'))
	{
		write(1, "Error\nInvalide Map !\n", 21);
		exit(EXIT_FAILURE);
	}
	if (!compare_char(str[--len], 'e'))
	{
		write(1, "Error\nInvalide Map !\n", 21);
		exit(EXIT_FAILURE);
	}
	if (!compare_char(str[--len], 'b'))
	{
		write(1, "Error\nInvalide Map !\n", 21);
		exit(EXIT_FAILURE);
	}
	if (!compare_char(str[--len], '.'))
	{
		write(1, "Error\nInvalide Map !\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	is_map_valid(t_long_data *data)
{
	int		fd;

	fd = open(data->file_name, O_RDONLY);
	data->y = map_len(fd);
	close(fd);
	if (data->y < 3)
		found_error();
	fd = open(data->file_name, O_RDONLY);
	check_map_content(data, fd);
	close(fd);
	store_map(data);
}

void	store_map(t_long_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(data->file_name, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * data->y + 1);
	if (!data->map)
		found_error();
	while (i < data->y)
		data->map[i++] = get_next_line(fd);
	data->map[i] = NULL;
}

void	check_map_content(t_long_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	data->x = ft_strlen(line);
	if (line[data->x - 1] == '\n')
		data->x--;
	while (i < data->y && line)
	{
		if (i == 0 || i == data->y - 1)
			check_wall(line, data);
		else
			check_line(line, data, 0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	free(line);
}
