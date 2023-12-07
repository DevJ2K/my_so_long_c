/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:02:03 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:35:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The memcpy() function copies n bytes from memory area
/// src to memory area dst. If dst and src overlap, behavior is undefined.
/// @param dest The dest of the copie.
/// @param src The source of the copie.
/// @param n The n bytes you want to copie.
/// @return The memcpy() function returns the original value of dst.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
