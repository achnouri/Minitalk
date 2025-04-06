/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:12 by achnouri          #+#    #+#             */
/*   Updated: 2025/02/01 02:07:42 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

static void	confirmation(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("-------------------------------------------------------\n");
		ft_printf("\033[42m\033[1m\033[37m -- Message Received -- \033[0m\n");
		ft_printf("-------------------------------------------------------\n");
	}
}

static int	ft_atoi(char *x)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while ((*(x + i) <= 9 && *(x + i) >= 13) || (*(x + i) == 32))
		i++;
	while (*(x + i) == 43 || *(x + i) == 45)
	{
		if (*(x + i) == 45)
			s *= (-1);
		i++;
	}
	while (*(x + i) >= 48 && *(x + i) <= 57)
	{
		r = (r * 10) + (*(x + i) - 48);
		i++;
	}
	r *= s;
	return (r);
}

static void	ft_handler(int p, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if (c & (1 << b))
			kill(p, SIGUSR1);
		else
			kill(p, SIGUSR2);
		usleep(250);
		usleep(50);
		b++;
	}
}

int	main(int ac, char **av)
{
	int	p;
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (ac != 3 || av[1][0] == '\0' || av[2][0] == '\0')
		return (ft_printf("\033[31mInvalid Input ! ❌\033[37m\n"), 1);
	while (av[1][l])
	{
		if (!(av[1][l] >= '0' && av[1][l] <= '9'))
			return (ft_printf("\033[31mInvalid Input ! ❌\033[37m\n"), 1);
		l++;
	}
	if (ac == 3)
	{
		p = ft_atoi(av[1]);
		while (av[2][i])
			ft_handler(p, av[2][i++]);
		signal(SIGUSR2, confirmation);
		ft_handler(p, '\0');
	}
	return (0);
}
