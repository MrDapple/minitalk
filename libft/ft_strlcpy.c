/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:46:25 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:38:09 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cd;
	size_t	cs;
	size_t	clen;

	cd = 0;
	cs = 0;
	clen = ft_strlen(src);
	if (dstsize == 0)
		return (clen);
	while (src[cs] != '\0' && cd < dstsize - 1)
	{
		dst[cd] = src[cs];
		cd++;
		cs++;
	}
	dst[cd] = '\0';
	return (clen);
}
