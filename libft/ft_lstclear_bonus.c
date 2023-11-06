/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:10:35 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 15:22:24 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*buff;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		buff = temp;
		(*del)(temp->content);
		temp = temp->next;
		free(buff);
	}
	*lst = NULL;
}
