/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:22:15 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/27 17:34:53 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		if (str[i] >= '0' && str[i] <= '9')
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
	char *str1 = "12d45";
	char *str2 = "12345";

	printf("%d\n", ft_str_is_numeric(str1));
	printf("%d\n", ft_str_is_numeric(str2));

	return (0);
}*/
