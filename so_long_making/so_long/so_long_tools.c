/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:48:49 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/03 06:04:07 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int compare_char(char a, char b)
{
	return (a == b);
}

void    check_map_name(char *str)
{
	int len;

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
	line  = get_next_line(fd);
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
		line  = get_next_line(fd);
		i++;
	}
	close (fd);
	free(line);
}

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
int check_other_char (t_long_data *data)
{
	int i = 0;
	int j;
	while(data->map[i])
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

int	compare_line_len(int len, char *str)
{
	int	l;

	l = ft_strlen(str);
	if (str[l - 1] == '\n')
		l--;
	return (len == l);
}

int		map_len(int fd)
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
	while (mc->p->y < mc->data->y)
	{
		mc->p->x = 0;
		while (mc->p->x < mc->data->x)
		{
			if (mc->data->map[mc->p->y][mc->p->x] == 'P')
				return ;
			mc->p->x++;
		}
		mc->p->y++;
	}
}