/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:15:38 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/07 20:36:50 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*sec;

	temp = *lst;
	while (temp != NULL)
	{
		del(temp->content);
		sec = temp->next;
		free(temp);
		temp = sec;
	}
	*lst = NULL;
}
