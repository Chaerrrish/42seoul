/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:49:23 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/01 20:01:54 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		if (str[i] >= 32 && str[i] <= 126)
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	char *str1 = "hello";
	char *str2 = "nice to meet you\n";

	printf("%d\n", ft_str_is_printable(str1));
	printf("%d\n", ft_str_is_printable(str2));
	return (0);
}
