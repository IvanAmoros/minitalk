/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:41:47 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/11 18:35:46 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*fin;
	char	*org;
	int		i;

	fin = (char *)dst;
	org = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(fin + i) = *(org + i);
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			*(fin + i) = *(org + i);
	}
	return (dst);
}
