/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:52 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/08 11:40:30 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

static void	lstadd_back(t_map **lst, t_map *new)
{
	t_map	*start;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		start = *lst;
		while (start->next)
			start = start->next;
		start->next = new;
	}
}

t_map	*get_map(char *filepath)
{
	int		fd;
	t_map	*maps;
	t_map	*line;

	fd = ft_open(filepath, 'r');
	maps = NULL;
	while (1)
	{
		line = malloc(sizeof(t_map));
		if (!line)
			ft_error("Failed to allocate memory.", 1);
		line->line = get_next_line(fd);
		if (!(line->line))
		{
			free(line);
			break ;
		}
		line->line_length = ft_linelength(line->line);
		line->next = NULL;
		lstadd_back(&maps, line);
	}
	lstadd_back(&maps, NULL);
	return (maps);
}


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
