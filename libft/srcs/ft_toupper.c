/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:57:55 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 23:04:10 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/// @brief The ft_toupper() function converts an lower-case letter
/// to the corresponding lower-case letter.
/// @param c The character you want to convert.
/// @return If the argument is an lower-case letter, the toupper()
/// function returns the corresponding upper-case letter if there
/// is one; otherwise, the argument is returned unchanged.
int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c", toupper('c'));
// 	printf("%c", toupper('D'));
// 	printf("%c", toupper('z'));
// 	printf("%c", toupper('a'));
// 	printf("%c", toupper('4'));
// }
