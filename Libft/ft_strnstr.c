/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:46:47 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/19 14:48:32 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_str(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (1)
		{
			if (needle[j] == '\0' && i + j <= len)
				return ((char *)&haystack[i]);
			if (haystack[i + j] != needle[j] || i + j > len)
				break ;
			else
				j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*rt;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	if (haystack[0] == '\0')
		return (0);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	if (haystack == needle)
		return ((char *)&haystack[0]);
	rt = find_str(haystack, needle, len);
	return (rt);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[27] = "lorem ipsum dolor sit amet";
	char str2[6] = "dolor";
	int len = ft_strlen(str1);

	// char str1[27] = "lorem ipsum dolor sit amet";
	// char str2[6] = "ipsum";
	// int len = 15;

	char str[9] = "abcdefgh";

	char *s1 = "FF";
 	char *s2 = "see FF your FF return FF now FF";

	printf("%s\n", ft_strnstr("abc", "abcdef", 5));
	printf("%s\n", strnstr("abc", "abcdef", 5));
	return (0);
}*/
