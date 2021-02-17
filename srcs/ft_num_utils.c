/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:23:30 by gaguado-          #+#    #+#             */
/*   Updated: 2021/02/17 14:24:06 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	ft_base(int i)
{
	if (i > 9)
		return (i - 10 + 97);
	return (i + 48);
}

void	ft_putnubrbase(unsigned long x, int may, int base)
{
	if (x / base > 0)
		ft_putnubrbase(x / base, may, base);
	ft_putchar_fd((may) ? ft_toupper(ft_base(x % base)) : ft_base(x % base), 1);
}
