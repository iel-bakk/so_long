/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:25:11 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/10/31 05:32:45 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h> //for testing only

#define BUFFER_SIZE 100

typedef struct s_data
{
	char	*remainder;
	char	*line;
	int		faill;
}	t_data;

typedef struct s_long_data
{
	char 	**map;
	char	*file_name;
	int		x;
	int		y;
	int		collect;
	int		exit;
	int		player;
	int		lines_total;
}	t_long_data;

// parsing functions

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*mifree(char *str, char *s);
void	initialize_struct(t_long_data *data);
int		compare_char(char a, char b);
t_data	mifree_data(t_data data);
void	check_map_name(char *str);
void	found_error(void);
void	is_map_valid(t_long_data *data);
int		map_len(int fd);
void	check_map_content(t_long_data *data, int fd);
void	check_wall(char *str, t_long_data *data);
void	check_line(char *str, t_long_data *data);
int		collect_map_objects(char collect_me, t_long_data *data);

# endif
