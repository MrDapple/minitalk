/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:47:18 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 15:55:41 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		c1;
	size_t		c2;
	const char	*str2;
	const char	*str1;

	c1 = 0;
	c2 = 0;
	str1 = s1;
	str2 = s2;
	while (c1 < n)
	{
		if ((unsigned char)str1[c1] != (unsigned char)str2[c2])
			return ((unsigned char)str1[c1] - (unsigned char)str2[c2]);
		c1++;
		c2++;
	}
	return (0);
}
