/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 12:21:37 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/// @brief The length of the string.
/// @param s The string you want to get length.
/// @return The length of the string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// int main(void)
// {
// 	printf(ft_strlen("Salut !!") == strlen("Salut !!") ? "OK" : "WRONG");
// 	printf("\n");
// 	printf(ft_strlen("") == strlen("") ? "OK" : "WRONG");
// 	printf("\n");
// 	printf(ft_strlen(" ") == strlen(" ") ? "OK" : "WRONG");
// 	printf("\n");
// }
