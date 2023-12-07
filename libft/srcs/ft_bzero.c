/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:59:52 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:05:10 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The ft_bzero() function writes n zero bytes to the string s.
/// If n is zero, ft_bzero() does nothing.
/// @param s The pointer to the memory of the string.
/// @param n The number of zero you want to write to the string s.
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
