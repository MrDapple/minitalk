/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:10:45 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 14:36:47 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	h;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	h = 0;
	if (!dstsize && !dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst[i] && ((i + h) < dstsize - 1))
		i++;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[h] && ((i + h) < dstsize - 1))
	{
		if (dstsize > 0)
			dst[i + h] = src[h];
		h++;
	}
	if (dstsize >= 1)
		dst[i + h] = '\0';
	return (src_len + dst_len);
}
