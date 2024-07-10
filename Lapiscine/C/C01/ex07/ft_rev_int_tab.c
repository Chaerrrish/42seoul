/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:04:56 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/26 20:19:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}
/*
int	main(void)
{
	int size;
	int	i;
	int tab[7] = {1, 2, 3, 4, 5, 6, 7};

	size = 7;
	i = 0;
	ft_rev_int_tab(tab,size);

	while(i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}

	return (0);
}*/
