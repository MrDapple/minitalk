/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:48:19 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/12 16:58:12 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int				i = 0;
	static unsigned char	c;

	if (sig == SIGUSR2)
	{
		c = c << 1;
	}
	else if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID:	%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
