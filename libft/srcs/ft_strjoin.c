/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:51:32 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:49:19 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a new
/// string, which is the result of the concatenation
/// of ’s1’ and ’s2’.
/// @param s1 The prefix string.
/// @param s2 The suffix string.
/// @return The new string. NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	str = malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + i] = '\0';
	return (str);
}
