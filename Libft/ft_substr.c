/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:45:45 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/31 00:02:04 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((unsigned int)ft_strlen(s) < start)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		len = (size_t)ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}
