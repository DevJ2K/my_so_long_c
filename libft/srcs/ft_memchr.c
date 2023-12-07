/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:54:01 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:30:04 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The ft_memchr() function locates the first occurrence of c
/// (converted to an unsigned char) in string s.
/// @param s The pointer to the string.
/// @param c The character you want to locate.
/// @param n The n bytes you will check.
/// @return The ft_memchr() function returns a pointer to the byte located,
/// or NULL if no such byte exists within n bytes.
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;
	size_t					i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
