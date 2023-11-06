/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:59:03 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:05:22 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "";
	char		*res;
	static long	check;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!buff[0])
		check = read(fd, buff, BUFFER_SIZE);
	if (check == -1)
		return (0);
	buff[check] = '\0';
	res = av_gnl_logic(buff, check, res, fd);
	return (res);
}

char	*av_gnl_logic(char *buff, long check, char *res, int fd)
{
	while (av_check_nl(res) == NO && check > 0)
	{
		if (av_check_nl(buff) == YES && check > 0)
			res = av_line_join(res, buff);
		else if (av_check_nl(buff) == NO && check > 0)
		{
			res = av_line_join(res, buff);
			check = av_readnclear(fd, buff);
			if (check == -1)
			{
				free(res);
				return (0);
			}
			buff[check] = '\0';
			if (check != 0 && check != -1)
				res = av_line_join(res, buff);
		}
		av_buff_move(buff);
	}
	return (res);
}
