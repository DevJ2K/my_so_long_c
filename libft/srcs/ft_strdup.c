/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:28:54 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 11:13:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The ft_strdup() function allocates sufficient memory for a
/// copy of the string s, does the copy, and returns a pointer to it.
/// @param s The string you want to copie.
/// @return A pointer to the string.
char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	str = (char *)malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
