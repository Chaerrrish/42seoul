/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:12:47 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/04 14:12:49 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	input_str(char *ptr, char **strs, char *sep, int size)
{
	int	i;

	i = 1;
	ft_strcpy(ptr, *strs);
	while (i < size)
	{
		ft_strcat(ptr, sep);
		ft_strcat(ptr, *(strs + i));
		i++;
	}
	i = ft_strlen(ptr);
	ptr[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;
	int		sep_size;
	int		strs_size;

	if (size == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		ptr[0] = '\0';
		return (ptr);
	}
	i = 0;
	strs_size = 0;
	sep_size = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		strs_size += ft_strlen(*(strs + i));
		i++;
	}
	ptr = (char *)malloc(sizeof(char) * (strs_size + sep_size + 1));
	input_str(ptr, strs, sep, size);
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
	char *strs[] = {"Hi", "My", "name", "is", "Chaerin"};
	char *sep = ", ";

	printf("%s\n", ft_strjoin(5, strs, sep));
	
	return (0);
}*/