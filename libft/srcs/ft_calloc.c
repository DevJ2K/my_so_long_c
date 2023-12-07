/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:13 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:10:07 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The ft_calloc() function allocates enough space
/// for count objects that are size bytes of memory each and returns
/// a pointer to the allocated memory. The allocated memory is filled
/// with bytes of value zero.
/// @param nmemb The number of elements of your allocatio.
/// @param size The sizeof() each element.
/// @return The pointer to the allocated memory. NULL if memory allocation fails
/// or size is equal to 0.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total_size);
	return (memory);
}
