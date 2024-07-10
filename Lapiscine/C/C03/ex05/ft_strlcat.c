/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:46:05 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/30 16:20:07 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	while (dest[i] != '\0')
		i++;
	while (dest_len + j + 1 < size && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (dest_len > size)
		return (size + ft_strlen(src));
	else
		return (dest_len + ft_strlen(src));
}
/*
int main(void)
{
	char dest[10] = "abc";
	char src[7] = "defghi";
	char dest1[10] = "poi";

	// printf("%u\n", ft_strlcat(dest, src, 2));
	// printf("%lu\n", strlcat(dest, src, 2));
	printf("%u\n", ft_strlcat(dest, src, 8));
	printf("%lu\n", strlcat(dest1, src, 8));
	return (0);
}*/
