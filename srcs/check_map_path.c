/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:55:35 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 11:44:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

static int	find_path_exit(char **matrix, int i, int j, char from)
{
	int	find;

	find = 0;
	matrix[i][j] = '*';
	if (matrix[i][j + 1] == 'E')
		return (1);
	if (matrix[i][j - 1] == 'E')
		return (1);
	if (matrix[i + 1][j] == 'E')
		return (1);
	if (matrix[i - 1][j] == 'E')
		return (1);
	if (ft_strchr("0C", matrix[i][j + 1]) && from != 'R')
		find += find_path_exit(matrix, i, j + 1, 'L');
	if (ft_strchr("0C", matrix[i][j - 1]) && from != 'L')
		find += find_path_exit(matrix, i, j - 1, 'R');
	if (ft_strchr("0C", matrix[i + 1][j]) && from != 'B')
		find += find_path_exit(matrix, i + 1, j, 'T');
	if (ft_strchr("0C", matrix[i - 1][j]) && from != 'T')
		find += find_path_exit(matrix, i - 1, j, 'B');
	return (find);
}

static int	find_path_player(char **matrix, int i, int j, char from)
{
	int	find;

	find = 0;
	matrix[i][j] = '*';
	if (matrix[i][j + 1] == 'P')
		return (1);
	if (matrix[i][j - 1] == 'P')
		return (1);
	if (matrix[i + 1][j] == 'P')
		return (1);
	if (matrix[i - 1][j] == 'P')
		return (1);
	if (ft_strchr("0C", matrix[i][j + 1]) && from != 'R')
		find += find_path_player(matrix, i, j + 1, 'L');
	if (ft_strchr("0C", matrix[i][j - 1]) && from != 'L')
		find += find_path_player(matrix, i, j - 1, 'R');
	if (ft_strchr("0C", matrix[i + 1][j]) && from != 'B')
		find += find_path_player(matrix, i + 1, j, 'T');
	if (ft_strchr("0C", matrix[i - 1][j]) && from != 'T')
		find += find_path_player(matrix, i - 1, j, 'B');
	return (find);
}

static int	handle_collectibles(t_map *map, int i, int j)
{
	int		valid_path;
	char	**tmp_map;

	tmp_map = get_tab_format_map(map);
	if (!tmp_map)
		return (-1);
	valid_path = find_path_player(tmp_map, i, j, 0);
	ft_free_tab(tmp_map);
	if (valid_path == 0)
		return (0);
	if (valid_path == -1)
		return (-1);
	return (valid_path);
}

static int	navigate_throw_tab(t_map *map, char **tab)
{
	int	i;
	int	j;
	int	nb_path;
	int	path_coins;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'P')
				nb_path = find_path_exit(tab, i, j, 0);
			if (tab[i][j] == 'C')
			{
				path_coins = handle_collectibles(map, i, j);
				if (path_coins == 0)
					return (0);
				if (path_coins == -1)
					return (-1);
			}
		}
	}
	return (nb_path);
}

int	exist_valid_path(t_map *map)
{
	char	**tab;
	int		nb_path;

	tab = get_tab_format_map(map);
	if (!tab)
		return (-1);
	nb_path = navigate_throw_tab(map, tab);
	ft_free_tab(tab);
	return (nb_path);
}
