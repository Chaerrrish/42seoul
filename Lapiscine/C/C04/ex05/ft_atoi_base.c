/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:01:11 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 22:01:13 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
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
		if (!(base[i] > 32 && base[i] <= 126))
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

int	str_space(char *str, int *flag)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			*flag *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	value;
	int				i;
	int				flag;
	int				base_len;

	base_len = ft_strlen(base);
	value = 0;
	flag = 1;
	if (check_base(base, base_len) == 1)
		return (0);
	i = str_space(str, &flag);
	while (str[i] != '\0')
	{
		if (base_index(str[i], base) != -1)
			value = (value * base_len) + base_index(str[i], base);
		else
			break ;
		i++;
	}
	return (value * flag);
}


#include <stdio.h>
int main(void)
{
	char *str = "52";
	char *base = "01234567";

	printf("%d\n", ft_atoi_base(str, base));

	return (0);
}