/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:07:59 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/05 16:08:01 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	count(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (check(str[i], charset) == 1)
		{
			cnt++;
			while (check(str[i], charset) == 1 && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	*ft_strncpy(char *dest, char *src, unsigned int s, unsigned int e)
{
	unsigned int	i;

	i = 0;
	while (s < e)
	{
		dest[i] = src[s];
		i++;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;
	int		cnt;

	i = 0;
	j = 0;
	cnt = count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	while (str[i] != '\0')
	{
		if (check(str[i], charset) == 1)
		{
			cnt = i;
			while (check(str[cnt], charset) == 1 && str[cnt] != '\0')
				cnt++;
			arr[j] = (char *)malloc(sizeof(char) * (cnt - i + 1));
			arr[j] = ft_strncpy(arr[j], str, i, cnt);
			i = cnt;
			j++;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "catxdogxybirdy";
	char *charset = "xyz";
	int i = 0;
	char **arr;
	arr = ft_split(str, charset);
	while (arr[i] != 0)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}*/