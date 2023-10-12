/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:12:15 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/12 17:49:09 by anvoets          ###   ########.fr       */
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
		if(chr & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (1);
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (0);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	return (0);
}
