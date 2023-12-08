/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:49 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 09:48:31 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include "mlx.h"

static void	init_vars(t_vars *vars, t_map **map)
{
	int		w_height;
	int		w_width;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_free_map(map);
		ft_error("Failed to allocate memory.", 1);
	}
	vars->mlx = mlx_init();
	vars->tile_size = 48;
	w_width = (*map)->line_length * vars->tile_size;
	w_height = size_of_map(*map) * vars->tile_size;
	vars->win = mlx_new_window(vars->mlx, w_width, w_height, "CRACKLANDERS");
	vars->map = map;
	game->coins_left = 0;
	game->count_moves = 0;
	vars->game = game;
	vars->matrix = get_tab_format_map(*map);
	if (!vars->matrix)
	{
		ft_free_vars(vars);
		ft_error("Failed to allocate memory.", 1);
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		exist_path;
	t_vars	vars;

	check_valid_args(argc, argv);
	map = get_map(argv[1]);
	check_valid_map(map);
	exist_path = exist_valid_path(map);
	if (exist_path <= 0)
	{
		ft_free_map(&map);
		if (exist_path == -1)
			ft_error("Failed to allocate memory.", 1);
		else if (exist_path == 0)
			ft_error("Not valid path found.", 1);
	}
	init_vars(&vars, &map);
	so_long(&vars);
}
