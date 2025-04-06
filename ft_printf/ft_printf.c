/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:20 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:18:29 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list	vargs, const char spf)
{
	int	l;

	l = 0;
	if (spf == 'c')
		l += ft_putchar(va_arg(vargs, int));
	else if (spf == 's')
		l += ft_putstr(va_arg(vargs, char *));
	else if (spf == 'd' || spf == 'i')
		l += ft_putnbr(va_arg(vargs, int));
	else if (spf == 'u')
		l += ft_putunbr(va_arg(vargs, unsigned int));
	else if (spf == 'p')
		l += ft_putptr(va_arg(vargs, uintptr_t));
	else if (spf == 'x')
		l += ft_puthexnum(va_arg(vargs, unsigned int), 'x');
	else if (spf == 'X')
		l += ft_puthexnum(va_arg(vargs, unsigned int), 'X');
	else if (spf == '%')
		l += ft_putchar('%');
	else
		l += ft_putchar(spf);
	return (l);
}

int	ft_printf(const char	*spf, ...)
{
	va_list	vargs;
	int		l;

	l = 0;
	va_start(vargs, spf);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*spf)
	{
		if (*spf == '%')
		{
			spf++;
			if (*spf)
				l += ft_check_format(vargs, *spf);
		}
		else
			l += write(1, spf, 1);
		if (*spf)
			spf++;
	}
	va_end(vargs);
	return (l);
}
