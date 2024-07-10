/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:22:50 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/09 20:22:53 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	add(int a, int b);
extern int	sub(int a, int b);
extern int	mul(int a, int b);
extern int	div(int a, int b);
extern int	mod(int a, int b);
extern void	print_number(char *arr, int i);
extern void	print_real_number(int nb, char *arr);
extern void	ft_putnbr(int nb);

int	ft_atoi(char *str)
{
	int	i;
	int	flag;
	int	val;

	i = 0;
	flag = 1;
	val = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val * flag);
}

int	get_sign_num(char sign)
{
	if (sign == '+')
		return (0);
	else if (sign == '-')
		return (1);
	else if (sign == '*')
		return (2);
	else if (sign == '/')
		return (3);
	else if (sign == '%')
		return (4);
	else if (!(sign == '+' || sign == '-' \
	|| sign == '/' || sign == '%' || sign == '*'))
		return (-1);
	else
		return (-1);
}

int	check_sign(int a, int b, char sign)
{
	a = 0;
	if (get_sign_num(sign) == -1)
	{
		write(1, "0\n", 2);
		return (-1);
	}
	if (get_sign_num(sign) == 3 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (-1);
	}
	if (get_sign_num(sign) == 4 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	char	sign;
	int		(*fp[5])(int, int);

	if (ac > 4 || ac < 2)
		return (0);
	fp[0] = add;
	fp[1] = sub;
	fp[2] = mul;
	fp[3] = div;
	fp[4] = mod;
	a = ft_atoi(av[1]);
	sign = av[2][0];
	b = ft_atoi(av[3]);
	if (check_sign(a, b, sign) == -1)
		return (0);
	ft_putnbr(fp[get_sign_num(sign)](a, b));
	return (0);
}
