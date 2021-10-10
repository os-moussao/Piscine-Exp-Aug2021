/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:03:31 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 10:02:27 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_op_br(char c)
{
	return (c == '[' || c == '(' || c == '{');
}

int	is_cl_br(char c)
{
	return (c == ']' || c == ')' || c == '}');
}

int	is_match(char cl, char op)
{
	if (cl == ')')
		return (op == '(');
	else if (cl == ']')
		return (op == '[');
	else
		return (op == '{');
}

int	is_valid(char *str)
{
	char	stack[1024];
	int		i;

	i = 0;
	while (*str)
	{
		if (is_op_br(*str))
			stack[i++] = *str;
		else if (is_cl_br(*str))
		{
			if (is_match(*str, stack[i - 1]))
				i--;
			else
				return (0);
		}
		str++;
	}
	if (i)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (is_valid(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}	
}
