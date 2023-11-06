/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:12:15 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/06 15:39:05 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char chr)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = chr;
	while (i > 0)
	{
		i--;
		if (chr & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		exit(EXIT_FAILURE);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	exit(EXIT_FAILURE);
}
