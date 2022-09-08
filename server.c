#include <unistd.h>
#include <stdio.h>
#include <signal.h>

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
	printf("%c", total);
}

void	putnbr(int PID)
{
	char	numchar;
	int		divisor;
	int		nb;
	char	*txt;

	nb = PID;
	divisor = 1;
	txt = "PID: ";
	while(*txt)
	{
		write(1, txt, 1);
		txt++;
	}
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
	int	PID;
	int	test = 2000000;

	putnbr(getpid());
	signal(SIGUSR1, printCharacter);
	signal(SIGUSR2, printCharacter);
	while(1)
		sleep(1);
	return(0);
}