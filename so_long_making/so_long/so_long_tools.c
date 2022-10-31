/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:48:49 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/10/31 07:49:31 by iel-bakk         ###   ########.fr       */
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
	{
		printf("1\n");
		found_error();
		
	}
	fd = open(data->file_name, O_RDONLY);
	check_map_content(data, fd);
	
}

void	check_map_content(t_long_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line  = get_next_line(fd);
	data->x = ft_strlen(line);
	while (i < data->y)
	{
		if (i == 0 || i == data->y - 1)
			check_wall(line, data);
		else
			check_line(line, data);
		free(line);
		line  = get_next_line(fd);
		i++;
	}
	free(line);
}

void	check_line(char *str, t_long_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != data->x || data->x < 3)
	{
	printf("2\n");

		free(str);
		found_error();
	}
	while (str[i])
	{
		if (!compare_char(str[0], '1') || !compare_char(str[data->x - 1], '1'))
		{
			printf("3\n");
			free(str);
			found_error();
		}
		else if (!collect_map_objects(str[i], data))
		{
			printf("4\n");
			free(str);
			found_error();
		}
		i++;
	}
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
	else if (collect_me != '0' || collect_me != '1')
		return (0);
	return (1);
}

void	check_wall(char *str, t_long_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != data->x || data->x < 3)
	{
		printf("5\n");
		free(str);
		found_error();
	}
	while (str[i])
	{
		if (!compare_char(str[i], '1'))
		{
			printf("char is %c\n 6\n", str[i]);
			free(str);
			found_error();
		}
		i++;
	}
}

int		map_len(int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = get_next_line(fd);
	if (!tmp)
	{
		printf("7\n");
		found_error();
	}
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

void	remove_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}