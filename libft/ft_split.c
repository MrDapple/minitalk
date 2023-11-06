/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:11:37 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 14:31:09 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	av_countwords(const char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while ((unsigned char)s[i] == (unsigned char)c && s[i + 1])
			i++;
		if ((unsigned char)s[i] != (unsigned char)c && s[i])
		{
			cnt++;
			while ((unsigned char)s[i] != (unsigned char)c && s[i + 1])
				i++;
		}
		i++;
	}
	if (cnt <= 0)
		return (0);
	return (cnt);
}

static size_t	av_wordlen(const char *s, size_t pos, char c)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s[pos] != (unsigned char)c && s[pos])
	{
		pos++;
		i++;
	}
	if (i <= 0)
		return (0);
	return (i);
}

static char	**av_free(char **ptr, size_t len)
{
	while (len--)
	{
		free(ptr[len]);
	}
	free(ptr);
	return (0);
}

static char	**av_tabgen(const char *s, char c)
{
	char	**tab;
	size_t	pos_s;
	size_t	tab_w;

	pos_s = 0;
	tab_w = 0;
	tab = malloc(sizeof(char *) * (av_countwords(s, c) + 1));
	if (!tab || !s)
		return (0);
	tab[av_countwords(s, c)] = 0;
	while (s[pos_s] != '\0')
	{
		if ((unsigned char)s[pos_s] == (unsigned char)c && s[pos_s])
			pos_s++;
		else if (s[pos_s])
		{
			tab[tab_w] = malloc(sizeof(char) * (av_wordlen(s, pos_s, c) + 1));
			if (!tab[tab_w])
				return (av_free(tab, tab_w));
			ft_memset(tab[tab_w++], 0, av_wordlen(s, pos_s, c) + 1);
			pos_s = pos_s + av_wordlen(s, pos_s, c);
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_w;
	size_t	pos_s;
	size_t	i;

	i = 0;
	tab_w = 0;
	pos_s = 0;
	tab = av_tabgen(s, c);
	if (!tab)
		return (0);
	while (s[pos_s])
	{
		while ((unsigned char)s[pos_s] == (unsigned char)c && s[pos_s])
			pos_s++;
		i = 0;
		while ((unsigned char)s[pos_s] != (unsigned char)c && s[pos_s])
		{
			tab[tab_w][i++] = s[pos_s];
			pos_s++;
			if ((unsigned char)s[pos_s] == (unsigned char)c && s[pos_s])
				tab_w++;
		}
	}
	return (tab);
}
