/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:53 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/05 14:35:53 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

static int	count_c_in_map(t_map *map, char c)
{
	int	i;
	int	count;

	count = 0;
	while (map)
	{
		i = 0;
		while (i < map->line_length)
		{
			if (ft_toupper(map->line[i]) == c)
				count++;
			i++;
		}
		map = map->next;
	}
	return (count);
}

int	check_count_characters(t_map *map)
{
	if (count_c_in_map(map, 'C') < 1)
		return (0);
	else if (count_c_in_map(map, 'P') != 1)
		return (0);
	else if (count_c_in_map(map, 'E') != 1)
		return (0);
	return (1);
}
