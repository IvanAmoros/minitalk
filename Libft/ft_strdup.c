/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:26:55 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/19 20:29:39 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		p;

	p = 0;
	while (s1[p])
		p++;
	str = (char *)malloc((p + 1) * sizeof(char));
	if (!str)
		return (0);
	p = 0;
	while (s1[p])
	{
		str[p] = s1[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}
