/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:40:22 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/31 17:43:19 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_non_printable(unsigned char c)
{
	const char	hex[17] = "0123456789abcdef";
	int			x;
	int			y;

	ft_putchar(92);
	x = c / 16;
	y = c % 16;
	ft_putchar(hex[x]);
	ft_putchar(hex[y]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			print_non_printable(str[i]);
		i++;
	}
}
/*
int	main(void)
{
	char *str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	return (0);

}*/
