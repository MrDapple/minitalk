/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:20:20 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/01 14:59:09 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new;
	void	*temp;

	if (!f || !del)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			free(temp);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
