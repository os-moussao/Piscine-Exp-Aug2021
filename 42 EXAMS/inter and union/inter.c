#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	char	hash[256] = {0};

	char	*s1 = av[1], *s2 = av[2];
	while (*s2)
	{
		hash[(int)*s2] = 1;
		s2++;
	}
	while (*s1)
	{
		if (hash[(int)*s1] == 1)
		{
			putchar(*s1);
			hash[(int)*s1] = 0;
		}
		s1++;
	}
	putchar('\n');
}