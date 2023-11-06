/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:51 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:21 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	av_ret_len_hex(long n)
{
	long	len;
	long	buf;

	len = 1;
	buf = n;
	if (buf < 0)
	{
		buf *= -1;
		len++;
	}
	while (buf >= 16)
	{
		buf = buf / 16;
		len++;
	}
	return (len);
}

long	ft_printf_lower_hex(long n)
{
	long	ret;

	ret = av_ret_len_hex(n);
	if (n < 16 && n >= 0)
	{
		if (ft_printf_char("0123456789abcdef"[n]) == -1)
			return (-1);
	}
	else if (n < 0)
	{
		if (ft_printf_char('-') == -1)
			return (-1);
		if (ft_printf_lower_hex(n * -1) == -1)
			return (-1);
	}
	else if (n >= 16)
	{
		if (ft_printf_lower_hex(n / 16) == -1)
			return (-1);
		if (ft_printf_lower_hex(n % 16) == -1)
			return (-1);
	}
	return (ret);
}
