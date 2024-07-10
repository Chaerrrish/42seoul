/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:42:55 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/09 16:42:56 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int func(char *str)
{
	int i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>
int main(void)
{
	int (*f)(char *);
	f = func;
	char *tab[5] = {"hello", "monkey", "lio4n", "awer"};
	printf("%d\n", ft_any(tab, f));
	return (0);

} */