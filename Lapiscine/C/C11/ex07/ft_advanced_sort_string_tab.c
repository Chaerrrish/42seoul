/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:56:42 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/10 14:56:44 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	word_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{	
		i++;
	}
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		i;
	int		j;
	int		cnt;

	cnt = word_count(tab);
	i = 0;
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
/*
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}

#include <stdio.h>
int main(void)
{
	int (*cmp)(char *, char *);
	cmp = ft_strcmp;

	int i = 0;
	char *arr[6] = {"lion", "monkey", "cat", "dog", "elephant"};

	ft_advanced_sort_string_tab(arr, cmp);
	while (arr[i] != 0)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}*/