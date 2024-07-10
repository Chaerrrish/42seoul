/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:44:31 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/06 19:35:01 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ft_strlen(char *str);
extern int	check_base(char *base, int len);
extern int	base_index(char c, char *base);
extern int	str_space(char *str, int *flag);
extern char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	count_len(long value, int len)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		if (value < 0)
		{
			cnt++;
			value *= -1;
		}
		value /= len;
		cnt++;
	}
	return (cnt);
}

char	*from_base_to(long value, char *base_to)
{
	int		cnt;
	char	*ptr;
	int		len;
	int		idx;

	len = ft_strlen(base_to);
	idx = count_len(value, len) - 1;
	cnt = count_len(value, len);
	ptr = (char *)malloc((sizeof(char) * cnt) + 1);
	ptr[cnt] = '\0';
	if (value < 0)
	{
		ptr[0] = '-';
		cnt--;
		value *= -1;
	}
	while (cnt > 0)
	{
		ptr[idx] = base_to[value % len];
		value /= len;
		cnt--;
		idx--;
	}
	return (ptr);
}
