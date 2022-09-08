#include<stdio.h>

int	main(void)
{
	char	c = 'h';
	int		binary = 256;
	int		bits = 8;
	while(bits != 0)
	{
		if(c <= binary)
		{
			printf("0");
		}
		else
		{
			printf("1");
			c = c - binary;
		}
		binary = binary / 2;
		bits--;
	}
}