/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:40:07 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:49:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The ft_memcmp() function compares byte string s1 against byte
/// string s2.
/// Both strings are assumed to be n bytes long.
/// @param s1 The string you want to compare against the s2.
/// @param s2 The string you want to compare against the s1.
/// @param n The n bytes you want to compare.
/// @return The ft_memcmp() returns zero if the two strings are identical.
/// Otherwise returns a negative number if s2 is greater than s1 or a positive
/// number if s1 is greater than s2.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;
	size_t					i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
