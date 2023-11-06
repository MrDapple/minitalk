/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:27:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/13 14:24:54 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}
