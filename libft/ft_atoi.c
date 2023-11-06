/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:45:03 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/02 13:02:36 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	av_setpos(const char *str)
{
	int	pos;

	pos = 0;
	while (((str[pos] >= 9 && str[pos] <= 13) || str[pos] == 32)
		&& str[pos] != '\0')
		pos++;
	if ((str[pos] == '+' || str[pos] == '-') && str[pos] != '\0')
		pos++;
	return (pos);
}

static int	av_setmod(const char *str)
{
	int	pos;
	int	mod;

	pos = 0;
	mod = 1;
	while (((str[pos] >= 9 && str[pos] <= 13) || str[pos] == 32)
		&& str[pos] != '\0')
		pos++;
	if ((str[pos] == '+' || str[pos] == '-') && str[pos] != '\0')
	{
		if (str[pos] == '-')
			mod = mod * -1;
		pos++;
	}
	return (mod);
}

int	ft_atoi(const char *str)
{
	int			pos;
	int			mod;
	long int	res;
	long int	temp;

	res = 0;
	temp = 0;
	pos = av_setpos(str);
	mod = av_setmod(str);
	while ((str[pos] >= '0' && str[pos] <= '9') && str[pos] != '\0')
	{
		res = res * 10;
		res = res + (str[pos] - '0');
		pos++;
		if (temp > res && mod > 0)
			return (-1);
		if (temp > res && mod < 0)
			return (0);
		temp = res;
	}
	return (res * mod);
}
