#include <stdio.h>
#include <signal.h>

void	sendBits(int pidserver, char c)
{
	int		binary = 128;
	int		bit = 0;
	while(bit < 8)
	{
		if(c >= binary)
		{
			kill(pidserver, 1);
			c = c - binary;
		}
		else
		{
			kill(pidserver, 0);
		}
		binary = binary / 2;
		bit++;
	}
}

int	main(void)
{
	char	*str = "h";
	int		i = 0;
	int		pidserver = 14136;

	while(str[i])
	{
		sendBits(pidserver, str[i]);
		i++;
	}
}