/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:59 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 16:32:41 by tajavon          ###   ########.fr       */
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
		path = get_texture(vars, "empty.xpm");
	else if (ft_toupper(c_texture) == '1')
		path = get_texture(vars, "wall.xpm");
	else if (ft_toupper(c_texture) == 'C')
		path = get_texture(vars, "collect.xpm");
	else if (ft_toupper(c_texture) == 'E')
		path = get_texture(vars, "exit1.xpm");
	else if (ft_toupper(c_texture) == 'P')
		path = get_texture(vars, "p1.xpm");
	else if (ft_toupper(c_texture) == 'N')
		path = get_texture(vars, "opps.xpm");
	if (!path)
		close_window(vars);
	img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	free(path);
	if (!img)
		close_window(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}

void	display_player(t_vars *vars, char touch, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (touch == 'w')
		path = get_texture(vars, "p3.xpm");
	if (touch == 'a')
		path = get_texture(vars, "p4.xpm");
	if (touch == 'd')
		path = get_texture(vars, "p2.xpm");
	if (touch == 's')
		path = get_texture(vars, "p1.xpm");
	if (!path)
	{
		ft_putendl_fd("Error\nFailed to allocate memory.", 2);
		close_window(vars);
	}
	img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	free(path);
	if (!img)
		close_window(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}

void	display_count(t_vars *vars)
{
	char	*count;

	ft_printf("Count : %d\n", vars->game->count_moves);
	count = ft_itoa(vars->game->count_moves);
	if (!count)
		close_window(vars);
	display_image(vars, '1', 0, 0);
	if (vars->tile_size >= 32)
		mlx_string_put(vars->mlx, vars->win, 22, 24, 0xFF0000, count);
	else
		mlx_string_put(vars->mlx, vars->win, 1, 12, 0xFF0000, count);
	free(count);
}
