/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyokim <juyokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:10:56 by juyokim           #+#    #+#             */
/*   Updated: 2023/08/29 10:56:49 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	print_title(int x)
{
	int	i;

	if (x == 1)
	{
		ft_putchar('o');
	}
	else if (x == 2)
	{
		ft_putchar('o');
		ft_putchar('o');
	}
	else
	{
		i = 0;
		ft_putchar('o');
		while (i < x - 2)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	print_body(int x, int y)
{
	int	i;

	while (y--)
	{
		if (x <= 2)
		{
			while (x--)
			{
				ft_putchar('|');
			}
		}
		else
		{
			ft_putchar('|');
			i = 0;
			while (i < x - 2)
			{
				ft_putchar(' ');
				i++;
			}
			ft_putchar('|');
		}
		ft_putchar('\n');
	}
}

void	print_error(void)
{
	int		i;
	char	*error_msg;

	error_msg = "Input values should be larger than zero.\n";
	i = 0;
	while (i < 41)
	{
		ft_putchar(*(error_msg + i));
		i++;
	}
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
	{
		print_error();
	}
	else if (y == 1)
	{
		print_title(x);
	}
	else if (y == 2)
	{
		print_title(x);
		print_title(x);
	}
	else
	{
		print_title(x);
		print_body(x, y - 2);
		print_title(x);
	}
}
