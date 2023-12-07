/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:47:05 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:13:42 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if a character is a printable.
/// @param c The character you want to check.
/// @return 1 if is a printable, otherwise 0
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
