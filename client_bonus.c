/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:00:02 by iamoros-          #+#    #+#             */
/*   Updated: 2022/09/29 13:48:48 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	error_handler(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(EXIT_FAILURE);
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			write(1, "Wrong pid!\n", 11);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}

void	send_bits(int pidserver, unsigned char c)
{
	int	binary;
	int	bit;

	binary = 128;
	bit = 0;
	while (bit < 8)
	{
		if (c >= binary)
		{
			if (kill(pidserver, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
			usleep(500);
			c = c - binary;
		}
		else
		{
			if (kill(pidserver, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
			usleep(500);
			//pause();
		}
		binary = binary / 2;
		bit++;
		usleep(100);
	}
}

void	recived_bites(int bit)
{
	if (bit == SIGUSR1)
		write(1, "Bit recived!\n", 13);
	else
	{
		write(1, "Message recived correctly!\n", 29);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pidserver;

	i = 0;
	error_handler(argc, argv);
	pidserver = ft_atoi(argv[1]);
	signal(SIGUSR1, recived_bites);
	signal(SIGUSR2, recived_bites);
	while (argv[2][i])
		send_bits(pidserver, argv[2][i++]);
	send_bits(pidserver, argv[2][i]);
	while (1)
	{
		pause();
	}
}
