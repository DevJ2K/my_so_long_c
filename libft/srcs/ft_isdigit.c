/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:24:28 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:13:33 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if a character is a digit.
/// @param c The character you want to check.
/// @return 1 if is a digit, otherwise 0
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
