/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:59 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/07 10:57:29 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>

void	display_player(t_vars *vars, char touch, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (touch == 'w')
		path = ft_strdup("./textures/p3.xpm");
	if (touch == 'a')
		path = ft_strdup("./textures/p4.xpm");
	if (touch == 'd')
		path = ft_strdup("./textures/p2.xpm");
	if (touch == 's')
		path = ft_strdup("./textures/p1.xpm");
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
	mlx_string_put(vars->mlx, vars->win, 22, 24, 0xFF0000, count);
	free(count);
}
