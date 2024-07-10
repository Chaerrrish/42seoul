/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:54:45 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/10 14:54:49 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		cnt;
	char	*temp;

	i = 0;
	cnt = word_count(tab);
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
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
#include <stdio.h>
int main(void)
{
	char *arr[5] = {"lion", "cat", "dog", "elephant"};
	int i = 0;

	ft_sort_string_tab(arr);
	while (arr[i] != 0)
	{
		printf("%s\n", arr[i]);
		i++;
	}

}*/
