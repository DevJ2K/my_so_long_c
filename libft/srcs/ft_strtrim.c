/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:35:19 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:58:30 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/// @brief Allocates (with malloc(3)) and returns a copy of
/// ’s1’ with the characters specified in ’set’ removed
/// from the beginning and the end of the string.
/// @param s1  The string to be trimmed.
/// @param set The reference set of characters to trim.
/// @return The trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	while (in_set(set, s1[j]))
		j++;
	while (in_set(set, s1[s1_len - 1]) && j < s1_len)
		s1_len--;
	str = malloc((s1_len - j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < s1_len)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("salut les amis", "asu"));
// 	printf("%s\n", ft_strtrim("salut les amist", "asu"));
// 	printf("%s\n", ft_strtrim("sas", "asu"));
// 	printf("%s\n", ft_strtrim("s", "asu"));
// 	printf("%s\n", ft_strtrim("ssssteaaaa", "asu"));
// }
