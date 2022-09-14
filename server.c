#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	printCharacter(char	*byte)
{
	int		total = 0;
	int		i = 0;
	int		base = 128;

	while(byte[i])
	{
		if(byte[i] == '1')
		{
			total = total + base;
		}
		base = base / 2;
		i++;
	}
	write(1, &total, 1);
}

void	getBites(int bit)
{
	static char	character[8];
	static int	i = 0;

	if(bit == SIGUSR1)
	{
		character[i] = '1';
	}
	else if(bit == SIGUSR2)
	{
		character[i] = '0';
	}
	i++;
	if(i == 8)
	{
		i = 0;
		printCharacter(character);
	}
}

void	putnbr(int PID)
{
	char	numchar;
	int		divisor;
	int		nb;

	nb = PID;
	divisor = 1;
	write(1, "PID: ", 6);
	while(PID >= 10)
	{
		PID /= 10;
		divisor *= 10;
	}
	while(divisor >= 1)
	{
		numchar = nb / divisor + '0';
		write(1, &numchar, 1);
		nb %= divisor;
		divisor /= 10;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	putnbr(getpid());
	signal(SIGUSR1, getBites);
	signal(SIGUSR2, getBites);
	while(1)
		sleep(1);
	return(0);
}