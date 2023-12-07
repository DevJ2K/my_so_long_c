/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:15:11 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:40:52 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The function writes a string in a file descriptor.
/// @param c The string you want to write.
/// @param fd The file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
