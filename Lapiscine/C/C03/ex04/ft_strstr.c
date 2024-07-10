/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:24:20 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/30 16:18:56 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (1)
	{
		if (str[i] == '\0')
			break ;
		j = 0;
		while (1)
		{
			if (to_find[j] == '\0')
				return (&str[i]);
			if (str[i + j] != to_find[j])
				break ;
			else
				j++;
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char *str1 = "Hello";
	char *str2 = "el";

	printf("%s", ft_strstr(str1, str2));
	return (0);
}*/
