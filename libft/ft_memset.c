/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:42:05 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:25 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cnt;
	char	*buff;

	cnt = 0;
	buff = (char *)b;
	while (cnt < len)
	{
		buff[cnt] = c;
		cnt++;
	}
	return (b);
}
