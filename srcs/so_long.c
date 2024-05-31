/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:18:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/10 23:27:15 by tajavon          ###   ########.fr       */
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

int	key_press(int key, t_vars *vars)
{
	int	tls;

	tls = vars->tile_size;
	if (key == XK_Escape || key == XK_q)
		close_window(vars);
	if (key == XK_p || key == XK_space)
		handle_pushup(vars);
	if (key == XK_w || key == XK_Up)
		move_characters(vars, 'w', vars->game->pos_x, vars->game->pos_y - tls);
	if (key == XK_a || key == XK_Left)
		move_characters(vars, 'a', vars->game->pos_x - tls, vars->game->pos_y);
	if (key == XK_d || key == XK_Right)
		move_characters(vars, 'd', vars->game->pos_x + tls, vars->game->pos_y);
	if (key == XK_s || key == XK_Down)
		move_characters(vars, 's', vars->game->pos_x, vars->game->pos_y + tls);
	return (0);
}

void	so_long(t_vars *vars)
{
	generate_map(vars);
	display_count(vars);
	mlx_key_hook(vars->win, key_press, vars);
	mlx_hook(vars->win, 17, 0, &close_window, vars);
	mlx_loop(vars->mlx);
}
