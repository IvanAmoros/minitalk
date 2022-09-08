/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:30:53 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/29 19:37:56 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc((count * size) * sizeof(char));
	if (!str)
		return (0);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
