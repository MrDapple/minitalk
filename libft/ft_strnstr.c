/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:09:26 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:38:23 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	chay;
	size_t	cndl;

	chay = 0;
	cndl = 0;
	if (needle[cndl] == '\0')
		return ((char *)haystack);
	while (chay < len && haystack[chay] != '\0')
	{
		while ((chay + cndl) < len && (needle[cndl] == haystack[chay + cndl]))
		{
			cndl++;
			if (needle[cndl] == '\0')
				return ((char *)&haystack[chay]);
		}
		cndl = 0;
		chay++;
	}
	return (0);
}
