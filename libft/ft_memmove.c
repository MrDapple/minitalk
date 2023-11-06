/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:03 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:27 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*srcb;
	char		*dstb;

	if (!dst && !src)
		return (NULL);
	dstb = dst;
	srcb = src;
	if (srcb < dstb)
	{
		while (len--)
			dstb[len] = srcb[len];
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
