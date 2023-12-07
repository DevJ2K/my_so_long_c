/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:04:29 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 23:03:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/// @brief The ft_tolower() function converts an upper-case letter
/// to the corresponding lower-case letter.
/// @param c The character you want to convert.
/// @return If the argument is an upper-case letter, the tolower()
/// function returns the corresponding lower-case letter if there
/// is one; otherwise, the argument is returned unchanged.
int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c", tolower('C'));
// 	printf("%c", tolower('e'));
// 	printf("%c", tolower('Z'));
// 	printf("%c", tolower('A'));
// 	printf("%c", tolower('-'));
// 	printf("%c", tolower('4'));
// }
