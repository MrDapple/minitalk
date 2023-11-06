/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:22:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:08 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	av_ret_len(unsigned long n)
{
	unsigned long	len;
	unsigned long	buf;

	len = 1;
	buf = n;
	while (buf >= 10)
	{
		buf = buf / 10;
		len++;
	}
	return (len);
}

unsigned long	ft_printf_unsigned(unsigned long n)
{
	unsigned long	ret;

	ret = av_ret_len(n);
	if (n < 10 && n >= 0)
	{
		if ((int)ft_printf_char(n + '0') == -1)
			return (-1);
	}
	else if (n >= 10)
	{
		if ((int)ft_printf_unsigned(n / 10) == -1)
			return (-1);
		if ((int)ft_printf_unsigned(n % 10) == -1)
			return (-1);
	}
	return (ret);
}
