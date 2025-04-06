/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:02:54 by achnouri          #+#    #+#             */
/*   Updated: 2024/12/15 04:14:43 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	l;

	l = 0;
	if (s == NULL)
	{
		l += ft_putstr("(null)");
		return (l);
	}
	while (s && *s)
	{
		l += ft_putchar(*s);
		s++;
	}
	return (l);
}
