/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:13 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/10 22:33:49 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"

int	ft_linelength(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	close_window(t_vars *vars)
{
	ft_free_vars(vars);
	exit (0);
}

char	*get_texture(t_vars *vars, char *name)
{
	char	*path;

	if (vars->tile_size == 8)
		path = ft_strjoin("./textures8/", name);
	else if (vars->tile_size == 16)
		path = ft_strjoin("./textures16/", name);
	else if (vars->tile_size == 32)
		path = ft_strjoin("./textures32/", name);
	else if (vars->tile_size == 48)
		path = ft_strjoin("./textures48/", name);
	else if (vars->tile_size == 64)
		path = ft_strjoin("./textures64/", name);
	if (!path)
		return (NULL);
	return (path);
}

void	init_tile_size(t_vars *vars)
{
	if (size_of_map(*vars->map) <= 16 && vars->map[0]->line_length < 30)
		vars->tile_size = 64;
	else if (size_of_map(*vars->map) <= 20 && vars->map[0]->line_length < 40)
		vars->tile_size = 48;
	else if (size_of_map(*vars->map) <= 31 && vars->map[0]->line_length < 60)
		vars->tile_size = 32;
	else if (size_of_map(*vars->map) <= 62 && vars->map[0]->line_length < 121)
		vars->tile_size = 16;
	else
		vars->tile_size = 8;
}

int	print_c(char *str, char *color)
{
	int	return_value;

	return_value = ft_printf("%s%s%s", color, str, RESET);
	return (return_value);
}
