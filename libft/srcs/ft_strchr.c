/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:50:20 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:44:59 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/// @brief The ft_strchr() function locates the first occurrence of c
/// (converted to a char) in the string pointed to by s.  The terminating
/// null character is considered to be part of the string; therefore if c
/// is ‘\0’, the functions locate the terminating ‘\0’.
/// @param s The string you want to check.
/// @param c The character you want to locate.
/// @return The ft_strchr() function returns a pointer to the byte located,
/// or NULL if no such byte exists within n bytes.
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((const char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
