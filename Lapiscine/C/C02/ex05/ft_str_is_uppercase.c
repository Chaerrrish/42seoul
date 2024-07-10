/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_upeercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:35:21 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/28 14:45:21 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
/*
int main(void)
{
	char *str1 = "ABCDE";
	char *str2 = "ABcDE";

	printf("%d\n", ft_str_is_uppercase(str1));
	printf("%d\n", ft_str_is_uppercase(str2));

	return (0);
}*/
