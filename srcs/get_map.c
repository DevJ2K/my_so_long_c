/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:52 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 17:37:21 by tajavon          ###   ########.fr       */
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
