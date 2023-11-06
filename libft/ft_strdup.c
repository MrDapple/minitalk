/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:31:21 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:37:57 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = ft_strlen(s1);
	res = malloc(i + 1 * (sizeof(const char)));
	if (!res)
		return (0);
	while ((long)i >= 0)
	{
		res[i] = s1[i];
		i--;
	}
	return (res);
}
