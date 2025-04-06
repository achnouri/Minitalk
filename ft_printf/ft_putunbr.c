/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:59 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:15:38 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	l;

	l = 0;
	if (n <= 9)
		l += ft_putchar(n + 48);
	else
	{
		l += ft_putunbr(n / 10);
		l += ft_putunbr(n % 10);
	}
	return (l);
}
