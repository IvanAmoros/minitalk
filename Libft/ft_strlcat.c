/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:36:44 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/13 20:36:59 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	n;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	n = 0;
	while (src[n] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[n]));
}
