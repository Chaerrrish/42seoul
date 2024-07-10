/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:59:49 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/09 16:59:50 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
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
	char *tab[5] = {"h2ello", "m9onkey", "li5on", "awer"};
	printf("%d\n", ft_count_if(tab, 4, f));
	return (0);
}*/