/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:32:39 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:36:31 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	av_lastnbr(long nb)
{
	long	ret;

	ret = nb;
	while (ret > 9)
	{
		ret = ret % 10;
	}
	return (ret);
}

static long	av_nbrlen(long n)
{
	long	c;
	long	len;
	long	i;

	c = n;
	len = 0;
	i = 0;
	if (n < 0)
	{
		c = c * -1;
		i++;
	}
	while (c > 0)
	{
		len++;
		c = c / 10;
	}
	len = len + i;
	return (len);
}

static char	*av_setstr(char *res, long n, long len)
{
	int	mod;

	mod = 0;
	if (n < 0)
	{
		n = n * -1;
		res[0] = '-';
		mod = 1;
	}
	res[len] = '\0';
	len--;
	while (len >= mod)
	{
		res[len] = (char)av_lastnbr(n) + 48;
		len--;
		n = n - av_lastnbr(n);
		n = n / 10;
	}
	return (res);
}

static char	*av_exceptionset(int n)
{
	char	*res;
	int		c;

	c = 0;
	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (0);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	else
	{
		res = malloc(sizeof(char) * 12);
		if (!res)
			return (0);
		av_setstr(res, -2147483648, 11);
		return (res);
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*res;

	len = 0;
	if ((long)n < -2147483647 || n == 0)
	{
		res = av_exceptionset(n);
		if (!res)
			return (0);
		return (res);
	}
	else
	{
		len = av_nbrlen(n);
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
			return (0);
		av_setstr(res, n, len);
	}
	return (res);
}
