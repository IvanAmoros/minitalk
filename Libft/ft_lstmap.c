/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:26:59 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/30 00:23:57 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*sec;

	new = NULL;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		sec = f(lst->content);
		temp = ft_lstnew(sec);
		if (!temp)
		{
			del(sec);
			ft_lstclear(&temp, del);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
