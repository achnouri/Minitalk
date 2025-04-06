/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:44 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:11:37 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				l;

	l = 0;
	nb = (unsigned int)n;
	if (n < 0)
	{
		l += ft_putchar('-');
		nb = -n;
	}
	if (nb <= 9)
		l += ft_putchar(nb + '0');
	else
	{
		l += ft_putnbr(nb / 10);
		l += ft_putnbr(nb % 10);
	}
	return (l);
}
