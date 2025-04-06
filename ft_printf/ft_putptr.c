/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:49 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:27:17 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_addr(uintptr_t nb)
{
	int					l;
	unsigned long int	len_base;
	char				*base;

	l = 0;
	len_base = 16;
	base = "0123456789abcdef";
	if (nb < len_base)
		l += ft_putchar(base[nb % len_base]);
	else
	{
		l += ft_put_addr(nb / len_base);
		l += ft_put_addr(nb % len_base);
	}
	return (l);
}

int	ft_putptr(uintptr_t addr)
{
	int	l;

	l = 0;
	l += ft_putstr("0x");
	if (addr == 0)
		l += ft_putchar('0');
	else
		l += ft_put_addr(addr);
	return (l);
}
