/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:37:22 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/19 18:56:35 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s;
	size_t	len;
	char	*str;

	i = 0;
	s = ft_strlen(s1) + ft_strlen(s2);
	len = ft_strlen(s1);
	str = (char *)malloc((s + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
