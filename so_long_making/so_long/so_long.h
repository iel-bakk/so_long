/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bakk < iel-bakk@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:25:11 by iel-bakk          #+#    #+#             */
/*   Updated: 2022/11/04 04:03:46 by iel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h> //for testing only

# define BUFFER_SIZE 100
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define ESC_KEY 53

typedef struct s_data
{
	char	*remainder;
	char	*line;
	int		faill;
}	t_data;

typedef struct s_long_data
{
	char	**map;
	char	*file_name;
	int		x;
	int		y;
	int		collect;
	int		exit;
	int		player;
	int		lines_total;
}	t_long_data;

typedef struct s_content
{
	int			px;
	int			py;
	int			move;
	void		*mlx;
	void		*mlx_win;
	void		*player;
	void		*empty;
	void		*wall;
	void		*collect;
	void		*exit;
	int			width;
	int			height;
	int			x;
	int			y;
	t_long_data	*data;
}	t_content;

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
void	check_line(char *str, t_long_data *data, int zero);
int		collect_map_objects(char collect_me, t_long_data *data);
int		compare_line_len(int len, char *str);
void	store_map(t_long_data *data);
void	zero_check(int zero, char *str);
void	check_the_storage(t_long_data *data);
void	free_map(t_long_data *data);
int		check_other_char(t_long_data *data);
void	start_the_game(t_long_data *data, t_content *mc);
void	get_elements_addr(t_content *mc, t_long_data *data);
void	initialize_map_struct(t_content *mc);
void	print_element(char c, t_content *mc);
void	print_map(t_long_data *data, t_content *mc);
void	get_player_position(t_content *mc);
int		exit_n_free(t_content *mc);
void	player_down(t_content *mc);
void	player_left(t_content *mc);
void	player_right(t_content *mc);
void	player_up(t_content *mc);
int		mouvement(int key_value, t_content *mc);
void	ft_putnbr(int move);

#endif