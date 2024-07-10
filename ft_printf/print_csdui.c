/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:37:32 by chaoh             #+#    #+#             */
/*   Updated: 2023/11/12 17:01:03 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, int cnt)
{
	char	c;

	c = va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		cnt++;
	return (cnt);
}

int	print_str(va_list ap, int cnt)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		cnt += write(1, "(null)", 6);
		return (cnt);
	}
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		cnt++;
	}
	return (cnt);
}

int	print_dec(va_list ap, int cnt)
{
	int	n;

	n = va_arg(ap, int);
	cnt = ft_putnbr_fd(n, 1, cnt);
	return (cnt);
}

int	print_unsigned(va_list ap, int cnt)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	cnt = ft_putunbr(u, cnt);
	return (cnt);
}
