/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:12 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 10:15:43 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes as a parameter a node and frees the memory of
/// the node’s content using the function ’del’ given
/// as a parameter and free the node. The memory of
/// ’next’ must not be freed.
/// @param lst The node to free.
/// @param del The address of the function used to delete the content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}
