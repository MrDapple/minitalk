/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:29:10 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 10:37:54 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
	{
		if ((unsigned char)s[cnt] == (unsigned char)c)
			return ((char *)&s[cnt]);
		cnt++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[cnt]);
	return (0);
}
