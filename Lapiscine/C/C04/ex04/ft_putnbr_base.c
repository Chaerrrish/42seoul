/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:34:06 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/30 20:34:08 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_number_base(char *base, char *arr, int i)
{
	while (i >= 0)
	{
		write(1, base + arr[i], 1);
		if (i == 0)
			break ;
		i--;
	}
}

void	change_base(char *base, unsigned int nbr, char *arr, int len)
{
	int	n;
	int	i;

	i = 0;
	while (1)
	{
		n = nbr % len;
		nbr = nbr / len;
		arr[i] = n;
		if (nbr != 0)
		{
			i++;
		}
		if (nbr == 0)
			break ;
	}
	print_number_base(base, arr, i);
}

int	check_base(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len == 1 || base[0] == '\0')
		return (1);
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (!(base[i] >= 32 && base[i] <= 126))
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	char	arr[40];

	len = ft_strlen(base);
	if (check_base(base, len) == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	change_base(base, nbr, arr, len);
}

/*
int main(void)
{
	char *base = "0123456789";
	char *base2 = "abcdefgh";
	ft_putnbr_base(-2147483648, base);
	ft_putnbr_base(42, base2);
}*/