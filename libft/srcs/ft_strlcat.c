/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:54:34 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 22:53:20 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief strlcat() appends string src to the end of dst. It will
/// append at most dstsize - strlen(dst) - 1 characters.  It will then
/// NUL-terminate, unless dstsize is 0 or the original dst string was longer
/// than dstsize (in practice this should not happen as it means that either
/// dstsize is incorrect or that dst is not a proper string).
/// @param dst The destination of the concatenation.
/// @param src The source string.
/// @param size The full size of destination buffer.
/// @return The size of concatenation.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen((char *)src);
	len_dst = ft_strlen((const char *)dst);
	i = 0;
	if (size == 0)
		return (len_src);
	else if (size <= len_dst)
		return (size + len_src);
	while (src[i] && size && (--size - len_dst))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
