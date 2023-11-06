/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:24 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:06:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	av_check_arg(va_list args, char type)
{
	int	ret;

	ret = 0;
	if (type == 'c')
		ret = ft_printf_char(va_arg(args, int));
	else if (type == 'd' || type == 'i')
		ret = ft_printf_nb(va_arg(args, int));
	else if (type == 's')
		ret = ft_printf_str(va_arg(args, char *));
	else if (type == 'p')
		ret = ft_printf_void(va_arg(args, void *));
	else if (type == 'u')
		ret = ft_printf_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		ret = ft_printf_lower_hex(va_arg(args, unsigned int));
	else if (type == 'X')
		ret = ft_printf_upper_hex(va_arg(args, unsigned int));
	else if (type == '%')
		ret = ft_printf_char('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		buf;

	va_start(args, format);
	i = 0;
	total = 0;
	buf = 0;
	while (format[i])
	{
		if (format[i] != '%')
			buf = write(1, &format[i], 1);
		else if (format[i])
		{
			buf = av_check_arg(args, format[i + 1]);
			i++;
		}
		if (buf == -1)
			return (buf);
		total += buf;
		i++;
	}
	va_end(args);
	return (total);
}
