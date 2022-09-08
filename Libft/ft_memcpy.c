/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:42:10 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/11 13:34:14 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*org;
	char	*go;

	org = (char *)src;
	go = (char *)dst;
	while (n != 0)
	{
		if (go == 0 && org == 0)
			return (dst);
		*go = *org;
		org++;
		go++;
		n--;
	}
	return (dst);
}
