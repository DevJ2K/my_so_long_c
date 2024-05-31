/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:29:19 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/10 23:37:27 by tajavon          ###   ########.fr       */
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
		print_c("Ramène-moi plus qu'un sac et tu es libre !\n", ORANGE);
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

static void	handle_opps(t_vars *vars, int new_x, int new_y)
{
	if (vars->game->pushup >= 3)
	{
		print_c("Vous avez éliminé un policier !\n", RED);
		vars->game->fits = 'f';
		valid_move(vars, new_x, new_y);
	}
	else
	{
		print_c("Un soucis ? Retour dans ta cellule immediatement !!\n", RED);
		close_window(vars);
	}
}

void	move_characters(t_vars *vars, char touch, int new_x, int new_y)
{
	int	x;
	int	y;

	x = new_x / vars->tile_size;
	y = new_y / vars->tile_size;
	if (vars->matrix[y][x] == 'N')
		handle_opps(vars, new_x, new_y);
	if (vars->matrix[y][x] == '0' || vars->matrix[y][x] == 'C')
		valid_move(vars, new_x, new_y);
	else if (vars->matrix[y][x] == 'E' && vars->game->coins_left <= 0)
	{
		print_c("Vous avez réussi à vous échapper de CPRH-22 !\n", GREEN);
		close_window(vars);
	}
	else if (vars->matrix[y][x] == 'E')
		handle_exit(vars, touch, new_x, new_y);
	display_player(vars, touch, vars->game->pos_x, vars->game->pos_y);
}

void	handle_pushup(t_vars *vars)
{
	int		display;
	char	*path1;
	char	*path2;

	path1 = get_texture(vars, "p_push1.xpm");
	if (!path1)
		close_window(vars);
	path2 = get_texture(vars, "p_push2.xpm");
	if (!path2)
	{
		free(path1);
		close_window(vars);
	}
	display = handle_display_pushup(vars, vars->game, path1, path2);
	free(path1);
	free(path2);
	if (display == -1)
		close_window(vars);
	vars->game->pushup++;
	ft_printf("Push-up count : %s%d%s\n", PURPLE, vars->game->pushup, RESET);
	if (vars->game->pushup == 3)
		print_c("Vous avez la capacité de KO les policiers !\n", BLUE);
}
