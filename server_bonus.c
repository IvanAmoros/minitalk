/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:00:06 by iamoros-          #+#    #+#             */
/*   Updated: 2022/09/29 00:39:47 by iamoros-         ###   ########.fr       */
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

void	print_message(int sig, siginfo_t *siginfo, void *unused)
{
	static char	character[8];
	static int	i = 0;

	(void)unused;
	if (sig == SIGUSR1)
	{
		character[i++] = '1';
		kill(siginfo->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		character[i++] = '0';
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (i == 8)
	{
		i = 0;
		if (print_character(character) == 1)
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR2);
		}
	}
}

int	main(void)
{
	struct sigaction	reciver;

	putnbr(getpid());
	reciver.sa_flags = SA_SIGINFO;
	reciver.sa_sigaction = print_message;
	sigaction(SIGUSR1, &reciver, NULL);
	sigaction(SIGUSR2, &reciver, NULL);
	while (1)
		sleep(1);
	return (0);
}
