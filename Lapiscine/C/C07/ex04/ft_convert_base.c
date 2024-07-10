/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:44:12 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 18:44:14 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*from_base_to(long value, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
		if ((9 <= base[i] && base[i] <= 13) || base[i] == ' ')
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

int	str_space(char *str, long *flag)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long			value;
	int				from_base_len;
	long			flag;
	int				i;

	from_base_len = ft_strlen(base_from);
	value = 0;
	flag = 1;
	i = 0;
	if (check_base(base_from, ft_strlen(base_from)) == 1 \
	|| check_base(base_to, ft_strlen(base_to)) == 1)
		return (0);
	i = str_space(nbr, &flag);
	while (nbr[i] != '\0')
	{
		if (base_index(nbr[i], base_from) != -1)
			value = (value * ft_strlen(base_from)) \
			+ base_index(nbr[i], base_from);
		else
			break ;
		i++;
	}
	value = value * flag;
	return (from_base_to(value, base_to));
}

#include <stdio.h>
int main(void)
{
	char *nbr = "-0";
	char *base_from = "0123456789";
	char *base_to = "0123456";
	printf("%s\n", ft_convert_base(nbr, base_from, base_to));

	return (0);
}