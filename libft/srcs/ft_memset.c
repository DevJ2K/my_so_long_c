/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:18:48 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:39:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The memset() function writes n bytes of value c
/// (converted to an unsigned char) to the string c.
/// @param s The string you want to fill.
/// @param c The character you want to set.
/// @param n The n bytes you want to set.
/// @return The memset() function returns its first argument.
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	i = 0;
	cpy = s;
	while (i < n)
	{
		cpy[i] = c;
		i++;
	}
	return (s);
}
