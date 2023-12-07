/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:50:32 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 23:01:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/// @brief The ft_strrchr() function is identical to ft_strchr(),
/// except it locates the last occurrence of c.
/// @param s The string you want to check.
/// @param c The character you want to locate.
/// @return The ft_strrchr() function returns a pointer to the byte located,
/// or NULL if no such byte exists within n bytes.
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occ;

	i = 0;
	last_occ = NULL;
	while (s[i])
	{
		if (s[i] == (const char)c)
			last_occ = (char *)&s[i];
		i++;
	}
	if ((const char)c == '\0')
		last_occ = (char *)&s[i];
	return (last_occ);
}
