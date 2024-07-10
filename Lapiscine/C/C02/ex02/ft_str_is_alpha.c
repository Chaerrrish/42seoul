/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:37:30 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/27 17:14:56 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
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
		else if (str[i] >= 'a' && str[i] <= 'z')
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
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	
	str1 = "\0";
	str2 = "Hi.";
	str3 = "HELLO";

	printf("%d\n", ft_str_is_alpha(str1));
	printf("%d\n", ft_str_is_alpha(str2));
	printf("%d\n", ft_str_is_alpha(str3));
	return (0);
}*/