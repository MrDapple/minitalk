/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:01:22 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 13:49:50 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	av_setcmp(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if ((unsigned char)a - (unsigned char)set[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	r;
	size_t	h;
	char	*res;

	if (!s1 || !set)
		return (0);
	i = 0;
	r = ft_strlen(s1);
	h = 0;
	while (av_setcmp(s1[i], set) == 1 && i < r)
		i++;
	if (r <= 0)
		r++;
	while (av_setcmp(s1[r - 1], set) == 1 && i < r)
		r--;
	if (s1[0] == '\0')
		r = 0;
	res = malloc((r - i + 1) * sizeof(char));
	if (!res)
		return (0);
	while (i < r)
		res[h++] = (char)s1[i++];
	res[h] = '\0';
	return (res);
}
