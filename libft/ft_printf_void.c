/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:31 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:03 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	av_print_adr(unsigned long n)
{
	if (n < 16 && n >= 0)
		ft_printf_char("0123456789abcdef"[n]);
	else if (n < 0)
	{
		ft_printf_char('-');
		av_print_adr(n * -1);
	}
	else if (n >= 16)
	{
		av_print_adr(n / 16);
		av_print_adr(n % 16);
	}
}

static unsigned long	av_len(unsigned long n)
{
	unsigned long	buf;
	unsigned long	len;

	buf = n;
	len = 1;
	while (buf >= 16)
	{
		buf = buf / 16;
		len++;
	}
	return (len);
}

unsigned long	ft_printf_void(void *adr)
{
	unsigned long	ret;
	int				buf;

	ret = av_len((unsigned long)adr);
	buf = write(1, "0x", 2);
	if (buf == -1)
		return (buf);
	av_print_adr((unsigned long)adr);
	return (ret + 2);
}
