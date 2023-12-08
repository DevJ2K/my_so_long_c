/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:18:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 12:03:54 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>

void	generate_map(t_vars *vars)
{
	int		x;
	int		y;
	t_map	*map;

	y = 0;
	map = *(vars->map);
	while (map)
	{
		x = 0;
		while (x / vars->tile_size < map->line_length)
		{
			display_image(vars, map->line[x / vars->tile_size], x, y);
			if (ft_toupper(map->line[x / vars->tile_size]) == 'C')
				vars->game->coins_left++;
			if (ft_toupper(map->line[x / vars->tile_size]) == 'P')
			{
				vars->game->pos_x = x;
				vars->game->pos_y = y;
			}
			x += vars->tile_size;
		}
		y += vars->tile_size;
		map = map->next;
	}
}

void	so_long(t_vars *vars)
{
	generate_map(vars);
	display_count(vars);
	mlx_key_hook(vars->win, key_press, vars);
	mlx_hook(vars->win, 17, 0, &close_window, vars);
	mlx_loop(vars->mlx);
}
