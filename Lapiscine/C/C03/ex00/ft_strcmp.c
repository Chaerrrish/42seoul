/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:16 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/30 16:18:07 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i])
			break ;
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char *s1;
	char *s2;

	s1 = "hello";
	s2 = "helow";

	printf("%d", ft_strcmp(s1, s2));
	return (0);
}*/
