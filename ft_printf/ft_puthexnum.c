/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:39 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:28:55 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexnum(unsigned int n, char xoX)
{
	int		l;
	char	*b16;

	l = 0;
	if (xoX == 'x')
		b16 = "0123456789abcdef";
	if (xoX == 'X')
		b16 = "0123456789ABCDEF";
	if (n < 16)
		l += ft_putchar(b16[n % 16]);
	else
	{
		l += ft_puthexnum(n / 16, xoX);
		l += ft_puthexnum(n % 16, xoX);
	}
	return (l);
}
