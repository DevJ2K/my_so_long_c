/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:29:09 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/07 11:24:14 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

int	size_of_map(t_map *map)
{
	int	line_length;
	int	height_map;

	line_length = map->line_length;
	height_map = 0;
	while (map)
	{
		if (map->line_length != line_length)
			return (0);
		height_map++;
		map = map->next;
	}
	if (height_map < 3)
		return (0);
	return (height_map);
}

static int	check_only_valid_character(t_map *map)
{
	char	*valid_character;
	int		i;

	valid_character = ft_strdup("10PpEeCcNn");
	if (!valid_character)
		return (0);
	while (map)
	{
		i = 0;
		while (i < map->line_length)
		{
			if (!ft_strchr(valid_character, map->line[i]))
			{
				free(valid_character);
				return (0);
			}
			i++;
		}
		map = map->next;
	}
	free(valid_character);
	return (1);
}

static int	check_surrounded_by_walls(t_map *map)
{
	int	i;
	int	num_l;
	int	nb_lines;

	num_l = 0;
	nb_lines = size_of_map(map);
	while (map)
	{
		i = 0;
		while (i < map->line_length)
		{
			if ((!num_l || num_l == nb_lines - 1) && map->line[i] != '1')
				return (0);
			if (num_l)
			{
				if ((!i || i == map->line_length - 1) && map->line[i] != '1')
					return (0);
			}
			i++;
		}
		num_l++;
		map = map->next;
	}
	i = 0;
	return (1);
}

void	check_valid_args(int argc, char **argv)
{
	int		len_map;
	char	*file_ext;
	int		fd;

	if (argc == 1)
		ft_error("Missing map.", 1);
	if (argc > 2)
		ft_error("Too many arguments !", 1);
	len_map = ft_strlen(argv[1]);
	if (len_map < 5)
		ft_error("Format invalid.", 1);
	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext)
		ft_error("Extension not found.", 1);
	if (ft_strlen(file_ext) != 4 || ft_strncmp(file_ext, ".ber", 4))
		ft_error("Extension format invalid.", 1);
	fd = ft_open(argv[1], 'r');
	close(fd);
}

void	check_valid_map(t_map *map)
{
	if (!map)
		ft_error("The map is null.", 1);
	if (!size_of_map(map))
	{
		ft_free_map(&map);
		ft_error("Wrong map size.", 1);
	}
	if (!check_only_valid_character(map))
	{
		ft_free_map(&map);
		ft_error("Unauthorized character found.", 1);
	}
	if (!check_surrounded_by_walls(map))
	{
		ft_free_map(&map);
		ft_error("The map isn't surrounded by walls.", 1);
	}
	if (!check_count_characters(map))
	{
		ft_free_map(&map);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("A character does not appear or ", 2);
		ft_putstr_fd("appears more times than expected.\n", 2);
		exit (1);
	}
}
