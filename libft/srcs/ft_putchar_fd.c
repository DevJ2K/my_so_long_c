/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:08:06 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:39:41 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief The function writes a character in a file descriptor.
/// @param c The character you want to write.
/// @param fd The file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
