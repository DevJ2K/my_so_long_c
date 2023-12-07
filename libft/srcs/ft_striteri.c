/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:02:14 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:48:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Applies the function ’f’ on each character of
/// the string passed as argument, passing its index
/// as first argument. Each character is passed by
/// address to ’f’ to be modified if necessary.
/// @param s The string on which to iterate.
/// @param f The function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
