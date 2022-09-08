/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:43:35 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/30 22:33:22 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *dst, int size, int n)
{
	int	last;

	last = size;
	if (n == 0)
	{
		dst[0] = '0';
		dst[1] = '\0';
		return (dst);
	}
	while (n != 0)
	{
		dst[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
	dst[last] = '\0';
	return (dst);
}

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		n++;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;
	int		size;

	i = 0;
	size = ft_size(n);
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	if (n < 0)
	{
		dst[0] = '-';
		if (n == -2147483648)
		{
			dst[1] = '2';
			n = n + 2000000000;
		}
		n = n * -1;
	}
	dst = ft_fill(dst, size, n);
	return (dst);
}
