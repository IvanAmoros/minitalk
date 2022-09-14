#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	errorHandler(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(0);
	while(argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			printf("wrong pid\n");
			exit(0);
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

void	sendBits(int pidserver, char c)
{
	int		binary = 128;
	int		bit = 0;
	while(bit < 8)
	{
		if(c >= binary)
		{
			kill(pidserver, SIGUSR1);
			c = c - binary;
		}
		else
		{
			kill(pidserver, SIGUSR2);
		}
		binary = binary / 2;
		usleep(50);
		bit++;
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
}