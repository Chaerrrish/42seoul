/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:28:09 by chaoh             #+#    #+#             */
/*   Updated: 2023/09/13 19:28:11 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	print_file(int read_rt, char buff, int fd);
void	repeat_order(void);
void	treat_error(char *error, char **av, int i);
void	ft_cat(char **av, int i);

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		repeat_order();
		return (0);
	}
	else if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if (av[i][0] == '-' && av[i][1] == '\0')
			{
				repeat_order();
			}
			else
				ft_cat(av, i);
			i++;
		}
	}
	return (0);
}
