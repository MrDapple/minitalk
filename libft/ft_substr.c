/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:27:45 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:05:36 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	av_minsize(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len >= ft_strlen(s) - start && start < ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= len_s)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (0);
		substr[0] = '\0';
		return (substr);
	}
	substr = malloc((av_minsize(len_s, len) + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, &s[start], av_minsize(len_s, len) + 1);
	return (substr);
}
