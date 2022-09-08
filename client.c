#include<stdio.h>

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

void	sendBits(char c)
{
	int		binary = 128;
	int		bit = 0;
	char	byte[8];
	while(bit < 8)
	{
		if(c >= binary)
		{
			// printf("1");
			byte[bit] = '1';
			c = c - binary;
		}
		else
		{
			// printf("0");
			byte[bit] = '0';
		}
		binary = binary / 2;
		bit++;
		if(bit == 8)
			printCharacter(byte);
	}
}

int	main(void)
{
	char	*str = "h😀h";
	int		i = 0;

	while(str[i])
	{
		sendBits(str[i]);
		i++;
	}
}