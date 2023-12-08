/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:09 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 15:00:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char			*line;
	int				line_length;
	struct s_map	*next;
}					t_map;

typedef struct s_game
{
	int	pos_x;
	int	pos_y;
	int	count_moves;
	int	coins_left;
}		t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	**map;
	char	**matrix;
	int		tile_size;
	t_game	*game;
}			t_vars;

t_map	*get_map(char *filepath);
void	check_valid_args(int argc, char **argv);
void	check_valid_map(t_map *map);
int		ft_linelength(char *line);
int		check_count_characters(t_map *map);
void	ft_free_map(t_map **map);
void	ft_free_vars(t_vars *vars);
char	**ft_free_tab(char **tab);
int		size_of_map(t_map *map);
int		exist_valid_path(t_map *map);
void	so_long(t_vars *vars);
char	**get_tab_format_map(t_map *map);
int		key_press(int key, t_vars *vars);
int		close_window(t_vars *vars);
void	display_image(t_vars *vars, char c_texture, int x, int y);
void	generate_map(t_vars *vars);
void	display_player(t_vars *vars, char touch, int x, int y);
void	display_count(t_vars *vars);
char	*get_texture(t_vars *vars, char *name);
void	init_tile_size(t_vars *vars);

#endif
