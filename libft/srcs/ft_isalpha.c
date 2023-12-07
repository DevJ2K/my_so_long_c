/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:08:26 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:13:23 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if a character is a letter.
/// @param c The character you want to check.
/// @return 1 if is a letter, otherwise 0
int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
