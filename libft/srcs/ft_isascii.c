/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:34:32 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:13:16 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if a character is an ascii.
/// @param c The character you want to check.
/// @return 1 if is an ascii, otherwise 0
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
