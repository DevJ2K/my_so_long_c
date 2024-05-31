/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:19:09 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/10 23:34:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RED "\033[31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[38;5;208m"
# define PURPLE "\033[38;5;129m"
# define RESET "\033[0m"

typedef struct s_map
{
	char			*line;
	int				line_length;
	struct s_map	*next;
}					t_map;

typedef struct s_game
{
	int		pos_x;
	int		pos_y;
	char	fits;
	int		pushup;
	int		count_moves;
	int		coins_left;
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
int		print_c(char *str, char *color);
void	display_player(t_vars *vars, char touch, int x, int y);
void	display_count(t_vars *vars);
int		handle_display_pushup(t_vars *vars, t_game *g, char *p1, char *p2);
void	move_characters(t_vars *vars, char touch, int new_x, int new_y);
void	handle_pushup(t_vars *vars);
char	*get_texture(t_vars *vars, char *name);
void	init_tile_size(t_vars *vars);

#endif
