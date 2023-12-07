/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:09:18 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/06 22:11:02 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	ft_free_map(t_map **map)
{
	t_map	*temp;
	t_map	*to_del;

	if (!map || !(*map))
		return ;
	temp = *map;
	while (temp)
	{
		to_del = temp;
		temp = temp->next;
		free(to_del->line);
		free(to_del);
	}
	*map = NULL;
}

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	ft_free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->game);
	if (vars->matrix)
		ft_free_tab(vars->matrix);
	if (vars->map)
		ft_free_map(vars->map);
}
