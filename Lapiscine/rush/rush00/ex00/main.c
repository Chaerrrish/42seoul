/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyokim <juyokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:10:32 by juyokim           #+#    #+#             */
/*   Updated: 2023/08/29 10:47:20 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647
#define ERROR_INT_OVERFLOW "Input should be less than 2147483648.\n"
#define ERROR_NON_NUMERIC "Input should not have non-numeric characters.\n"
#define ERROR_ARGS "There should be two input arguments.\n"

extern void	rush(int x, int y);
extern void	ft_putchar(char c);

void	ft_print_error_msg(char *msg, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(*msg);
		msg++;
		i++;
	}
}

int	ft_atoi(char *str)
{
	long long	val;

	val = 0;
	while (*str != 0)
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	if (val > INT_MAX)
	{
		ft_print_error_msg(ERROR_INT_OVERFLOW, 38);
		return (-1);
	}
	return ((int)val);
}

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (*(str + i) != 0)
	{
		c = *(str + i);
		i++;
		if (c >= '0' && c <= '9')
		{
			continue ;
		}
		else
		{
			ft_print_error_msg(ERROR_NON_NUMERIC, 46);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		ft_print_error_msg(ERROR_ARGS, 37);
	}
	else if (ft_str_is_numeric(argv[1]) && ft_str_is_numeric(argv[2]))
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x != -1 && y != -1)
		{
			rush(x, y);
		}
	}
	return (0);
}
