#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	errorHandler(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(EXIT_FAILURE);
	while(argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			printf("wrong pid\n");
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
	while(str[i])
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return(nbr);
}

void	sendBits(int pidserver, unsigned char c)
{
	int		binary = 128;
	int		bit = 0;
	while(bit < 8)
	{
		if(c >= binary)
		{
			if (kill(pidserver, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
			c = c - binary;
		}
		else
		{
			if (kill(pidserver, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		binary = binary / 2;
		usleep(50);
		bit++;
	}
}

void	recived_bites(int bit)
{
	if (bit == SIGUSR1)
		write(1, "Bit recived!", 12);
	else
	{
		write(1, "Message recived correctly!", 28);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int		i = 0;
	int		pidserver;

	errorHandler(argc, argv);
	pidserver = ft_atoi(argv[1]);
	while(argv[2][i])
		sendBits(pidserver, argv[2][i++]);
	sendBits(pidserver, '\n');
	signal(SIGUSR1, recived_bites);
	signal(SIGUSR2, recived_bites);
	return(0);
	// while(1)
	// 	pause();
}
