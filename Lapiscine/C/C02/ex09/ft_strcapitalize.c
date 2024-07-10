/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:50:06 by chaoh             #+#    #+#             */
/*   Updated: 2023/08/28 22:09:44 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	upper_alp(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	lower_alp(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag == 1 && lower_alp(str[i]) == 1)
		{
			flag = 0;
			str[i] = str[i] - 32;
		}
		else if (flag == 0 && upper_alp(str[i]) == 1)
			str[i] = str[i] + 32;
		if (upper_alp(str[i]) || lower_alp(str[i]) || is_num(str[i]))
		{
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (str);
}
/*
int main(void)
{
    char str[70] = "salut, comment tu vas ?
   	42mots quarante-deux; cinquante+et+un?";
    char *after;
    after = ft_strcapitalize(str);
    printf("%s\n", after);
    return (0);
}*/
