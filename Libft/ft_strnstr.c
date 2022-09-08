/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:43:31 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/26 00:37:17 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	l;

	i = 0;
	n = 0;
	l = ft_strlen(needle);
	if (l == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && haystack[i + n] != '\0'
			&& i + n < len)
		{
			n++;
		}
		if (n == l)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
