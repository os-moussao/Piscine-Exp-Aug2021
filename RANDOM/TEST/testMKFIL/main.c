#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	ft_putstr("putstr works");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	a = 97;
	b = 98;
	ft_swap(&a, &b);
	printf("%d	%d\n", a, b);
	printf("%d %d %d", ft_strcmp("abx", "abc"), ft_strlen("abx"), ft_strlen("ab"));
}
