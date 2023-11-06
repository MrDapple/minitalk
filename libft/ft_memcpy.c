/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:10:06 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:37:17 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srcb;
	char	*dstb;
	size_t	cnt;

	if (dst == NULL && src == NULL)
		return (0);
	dstb = (char *)dst;
	srcb = (char *)src;
	cnt = 0;
	while (cnt < n)
	{
		dstb[cnt] = (unsigned char)srcb[cnt];
		cnt++;
	}
	return (dst);
}
