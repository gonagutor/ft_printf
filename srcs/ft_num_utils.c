/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:23:30 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/10 19:23:53 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	ft_base(int i)
{
	if (i > 9)
		return (i - 10 + 97);
	return (i + 48);
}

int		ft_putnubrbase(unsigned long x, int may, int base)
{
	int ret;

	ret = 0;
	if (x / base > 0)
		ret += ft_putnubrbase(x / base, may, base) + 1;
	ft_putchar_fd((may) ? ft_toupper(ft_base(x % base)) : ft_base(x % base), 1);
	return (ret);
}

int		ft_ncbase(unsigned long x, int base)
{
	int ret;

	ret = 0;
	if (x / base > 0)
		ret += ft_ncbase(x / base, base) + 1;
	return ((ret == 0 && x == 0) ? 0 : ret);
}

long	ft_abs(long x)
{
	return (x > 0) ? x : x * -1;
}

int		ft_ncsigned(long x)
{
	int ret;

	ret = ft_ncbase(ft_abs(x), 10) + (int)(x < 0);
	return (ret);
}
