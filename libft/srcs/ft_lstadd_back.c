/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:43:25 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 10:15:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node ’new’ at the end of the list.
/// @param lst The address of a pointer to the first link of a list.
/// @param new The address of a pointer to the node to be added to the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

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
