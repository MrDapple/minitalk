/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:18:43 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 19:19:17 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	res = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			res[i] = (unsigned char)s1[i];
		else
			res[i] = (unsigned char)s2[i - len_s1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
