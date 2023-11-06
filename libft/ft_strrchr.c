/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:25:50 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:42:50 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	cnt;
	int	loc;

	cnt = 0;
	loc = -1;
	while (s[cnt] != '\0')
	{
		if ((unsigned char)s[cnt] == (unsigned char)c)
			loc = cnt;
		cnt++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[cnt]);
	if (loc < 0)
		return (0);
	if ((unsigned char)s[cnt] == '\0')
		return ((char *)&s[loc]);
	return (0);
}
