/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:25:27 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 15:55:46 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		cnt;

	str = s;
	cnt = 0;
	while ((long)cnt < (long)n)
	{
		if ((unsigned char)str[cnt] == (unsigned char)c)
			return ((void *)&s[cnt]);
		cnt++;
	}
	return (0);
}
