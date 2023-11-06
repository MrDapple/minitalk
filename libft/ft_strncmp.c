/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:39:22 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:38:20 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;
	size_t	res;

	cnt = 0;
	res = 0;
	while (cnt < n && (s1[cnt] || s2[cnt]))
	{
		if ((unsigned char)s1[cnt] == (unsigned char)s2[cnt])
			cnt++;
		else
		{
			res = (unsigned char)s1[cnt] - (unsigned char)s2[cnt];
			return (res);
		}
	}
	return (0);
}
