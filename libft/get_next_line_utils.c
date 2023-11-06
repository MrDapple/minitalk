/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:59:55 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:05:25 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	av_check_nl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NO);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (YES);
		i++;
	}
	return (NO);
}

size_t	av_line_len(char *str, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[cnt] != c && str[cnt] != '\0')
		cnt++;
	if (str[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*av_buff_move(char *buff)
{
	size_t	i;
	size_t	t;
	char	temp[BUFFER_SIZE + 1];

	i = 0;
	t = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i])
		i++;
	while (buff[i])
		temp[t++] = buff[i++];
	temp[t] = '\0';
	t = 0;
	while (temp[t])
	{
		buff[t] = temp[t];
		t++;
	}
	buff[t] = '\0';
	return (0);
}

size_t	av_readnclear(int fd, char *buff)
{
	size_t	check;
	size_t	i;

	check = 0;
	i = 0;
	while (buff[i])
	{
		buff[i] = '\0';
		i++;
	}
	check = read(fd, buff, BUFFER_SIZE);
	return (check);
}

char	*av_line_join(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	len_s1 = av_line_len(s1, '\0');
	len_s2 = av_line_len(s2, '\n');
	i = 0;
	res = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (0);
	}
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			res[i] = (unsigned char)s1[i];
		else
			res[i] = (unsigned char)s2[i - len_s1];
		i++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}
