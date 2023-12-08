/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:29:19 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 14:02:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>

static void	handle_exit(t_vars *vars, char touch, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (touch == 'w')
		path = get_texture(vars, "exit1.xpm");
	if (touch == 'a')
		path = get_texture(vars, "exit2.xpm");
	if (touch == 'd')
		path = get_texture(vars, "exit4.xpm");
	if (touch == 's')
		path = get_texture(vars, "exit3.xpm");
	if (!path)
		return ;
	img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	free(path);
	if (!img)
		close_window(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
	if (vars->game->coins_left > 1)
		ft_printf("Ramène-moi encore %d sacs !\n", vars->game->coins_left);
	else if (vars->game->coins_left == 1)
		ft_printf("Ramène-moi plus qu'un sac et tu es libre !\n");
}

static void	valid_move(t_vars *vars, int new_x, int new_y)
{
	int	x;
	int	y;
	int	tls;

	tls = vars->tile_size;
	x = new_x / tls;
	y = new_y / tls;
	if (++vars->game->count_moves && vars->matrix[y][x] == 'C')
		vars->game->coins_left--;
	display_count(vars);
	vars->matrix[vars->game->pos_y / tls][vars->game->pos_x / tls] = '0';
	display_image(vars, '0', vars->game->pos_x, vars->game->pos_y);
	vars->game->pos_x = new_x;
	vars->game->pos_y = new_y;
}

static void	move_characters(t_vars *vars, char touch, int new_x, int new_y)
{
	int	x;
	int	y;
	int	tls;

	tls = vars->tile_size;
	x = new_x / tls;
	y = new_y / tls;
	if (vars->matrix[y][x] == 'N')
	{
		ft_printf("T'as un soucis ? Retour dans ta cellule immediatement !!\n");
		close_window(vars);
	}
	if (vars->matrix[y][x] == '0' || vars->matrix[y][x] == 'C')
		valid_move(vars, new_x, new_y);
	else if (vars->matrix[y][x] == 'E' && vars->game->coins_left <= 0)
	{
		ft_printf("Bravo, vous avez réussi à vous échapper de CPRH-22 !\n");
		close_window(vars);
	}
	else if (vars->matrix[y][x] == 'E')
		handle_exit(vars, touch, new_x, new_y);
	display_player(vars, touch, vars->game->pos_x, vars->game->pos_y);
}

int	key_press(int key, t_vars *vars)
{
	int	tls;

	tls = vars->tile_size;
	if (key == XK_Escape || key == XK_q)
		close_window(vars);
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
