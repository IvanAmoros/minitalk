/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:00:24 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 19:44:52 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (n);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	numchar;
	int		divisor;
	int		nb;

	divisor = 1;
	n = ft_negative(n, fd);
	if (n == -2147483648)
		return ;
	nb = n;
	while (n >= 10)
	{
		n = n / 10;
		divisor = divisor * 10;
	}
	while (divisor >= 1)
	{
		numchar = nb / divisor + '0';
		write(fd, &numchar, 1);
		nb = nb % divisor;
		divisor = divisor / 10;
	}
}
