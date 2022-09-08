/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:48:54 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/28 18:00:07 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!*lst)
		*lst = new;
	else
	{
		element = *lst;
		while (element->next != NULL)
			element = element->next;
		element->next = new;
	}
}
