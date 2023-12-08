/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:55:35 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 10:01:20 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

char	**get_tab_format_map(t_map *map)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc((size_of_map(map) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (map)
	{
		j = 0;
		tab[i] = malloc((map->line_length + 1) * sizeof(char));
		if (!tab[i])
			return (ft_free_tab(tab));
		while (j < map->line_length)
		{
			tab[i][j] = ft_toupper(map->line[j]);
			j++;
		}
		tab[i++][j] = '\0';
		map = map->next;
	}
	tab[i] = NULL;
	return (tab);
}

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

static int	navigate_throw_tab(char **tab)
{
	int	i;
	int	j;
	int	nb_path;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				nb_path = find_path_exit(tab, i, j, 0);
			if (tab[i][j] == 'C')
			{
				if (find_path_player(tab, i, j, 0) == 0)
					return (0);
			}
			j++;
		}
		i++;
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
	nb_path = navigate_throw_tab(tab);
	ft_free_tab(tab);
	return (nb_path);
}
