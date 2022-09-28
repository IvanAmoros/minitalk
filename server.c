/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:59:40 by iamoros-          #+#    #+#             */
/*   Updated: 2022/09/29 00:10:40 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	print_character(char *byte)
{
	int	total;
	int	i;
	int	base;

	total = 0;
	i = 0;
	base = 128;
	while (byte[i])
	{
		if (byte[i] == '1')
			total = total + base;
		base = base / 2;
		i++;
	}
	if (total == '\0')
		return (1);
	write(1, &total, 1);
	return (0);
}

void	putnbr(int PID)
{
	char	numchar;
	int		divisor;
	int		nb;

	nb = PID;
	divisor = 1;
	write(1, "PID: ", 6);
	while (PID >= 10)
	{
		PID /= 10;
		divisor *= 10;
	}
	while (divisor >= 1)
	{
		numchar = nb / divisor + '0';
		write(1, &numchar, 1);
		nb %= divisor;
		divisor /= 10;
	}
	write(1, "\n", 1);
}

void	print_message(int sig)
{
	static char	character[8];
	static int	i = 0;

	if (sig == SIGUSR1)
		character[i++] = '1';
	else if (sig == SIGUSR2)
		character[i++] = '0';
	if (i == 8)
	{
		i = 0;
		if (print_character(character) == 1)
			write(1, "\n", 1);
	}
}

int	main(void)
{
	putnbr(getpid());
	signal(SIGUSR1, print_message);
	signal(SIGUSR2, print_message);
	while (1)
		sleep(1);
	return (0);
}
