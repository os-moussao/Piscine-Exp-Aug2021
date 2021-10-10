#include <unistd.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*get_first_word(char *str)
{
	char	*first_word;
	int		end;
	int		start;

	end = 0;
	while (str[end] && (str[end] == ' ' || str[end] == '\t'))
		end++;
	start = end;
	while (str[end] && !(str[end] == ' ' || str[end] == '\t'))
		end++;
	first_word = malloc(end - start + 1);
	ft_strncpy(first_word, str + start, end - start + 1);
	return (first_word);
}

int	skip_first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*first_word;
	int		write_space;

	if (argc == 2)
	{
		first_word = get_first_word(argv[1]);
		argv[1] = argv[1] + skip_first_word(argv[1]);
		write_space = *argv[1];
		while (*argv[1])
		{
			if (*argv[1] == ' ' || *argv[1] == '\t')
			{
				write(1, " ", 1);
				while (*argv[1] && (*argv[1] == ' ' || *argv[1] == '\t'))
					argv[1]++;
			}
			else
				write(1, argv[1]++, 1);
		}
		if (write_space)
			write(1, " ", 1);
		ft_putstr(first_word);
		free(first_word);
	}
	write(1, "\n", 1);
}
