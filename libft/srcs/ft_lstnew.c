/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:12:35 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 10:16:11 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a new node.
/// The member variable ’content’ is initialized with
/// the value of the parameter ’content’. The variable
/// ’next’ is initialized to NULL.
/// @param content  The content to create the node with.
/// @return The new node.
t_list	*ft_lstnew(void *content)
{
	t_list	*lnew;

	lnew = malloc(sizeof(t_list));
	if (!lnew)
		return (NULL);
	lnew->content = content;
	lnew->next = NULL;
	return (lnew);
}
