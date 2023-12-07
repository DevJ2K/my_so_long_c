/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:18:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/07 11:20:11 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>

void	display_image(t_vars *vars, char c_texture, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (ft_toupper(c_texture) == '0')
		path = ft_strjoin("./textures/", "empty.xpm");
	else if (ft_toupper(c_texture) == '1')
		path = ft_strjoin("./textures/", "wall.xpm");
	else if (ft_toupper(c_texture) == 'C')
		path = ft_strjoin("./textures/", "collect.xpm");
	else if (ft_toupper(c_texture) == 'E')
		path = ft_strjoin("./textures/", "exit1.xpm");
	else if (ft_toupper(c_texture) == 'P')
		path = ft_strjoin("./textures/", "p1.xpm");
	else if (ft_toupper(c_texture) == 'N')
		path = ft_strjoin("./textures/", "opps.xpm");
	img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	free(path);
	if (!img)
		close_window(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}

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
