/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:16:54 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/31 22:38:38 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned int i);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(unsigned long long addr)
{
	char	arr[16];
	int		i;

	i = 1;
	while (i <= 16)
	{
		arr[16 - i] = addr % 16;
		addr = addr / 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		print_hex(arr[i]);
		i++;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_str_to_hex(unsigned char *str,
unsigned int size, unsigned int offset)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (offset + i < size)
		{
			print_hex(str[i] / 16);
			print_hex(str[i] % 16);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	print_hex(unsigned int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[i]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned int	i;
	unsigned int	j;

	str = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)addr + i);
		print_str_to_hex(str + i, size, i);
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (str[i + j] >= 32 && str[i + j] <= 126)
				ft_putchar(str[i + j]);
			else
				ft_putchar('.');
			j++;
		}
		i += 16;
		ft_putchar('\n');
	}
	return (addr);
}

int main(void)
{
	char arr[] = "I ate Eggdrop today. I want to pass C02.";	
   	ft_print_memory(arr, 40);
	return (0);
}
