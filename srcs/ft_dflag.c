/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:01 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/18 18:42:47 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_dspaces(t_flags flg, unsigned long num, int neg)
{
	int	spaces;
	int	lzeros;
	int	numlen;

	spaces = 0;
	numlen = ft_ncbase(num, 10) + 1;
	if (num == 4294967284)
		numlen++;
	lzeros = 0;
	if (flg.dot_mod && flg.prec_mod > 0)
		lzeros = ft_abs(flg.prec_mod) - numlen
			+ (num == 0 && flg.dot_mod != 0);
	if (lzeros < 0 || flg.prec_mod < 0)
		lzeros = (num == 0);
	if (!neg)
		spaces = flg.flagqtt_mod - numlen - lzeros
			+ (num == 0 && flg.dot_mod != 0);
	else
		spaces = (flg.flagqtt_mod * -1) - numlen - lzeros
			+ (num == 0 && flg.dot_mod != 0);
	return (spaces);
}

int	ft_paddedprinting(t_flags flg, long num, int neg)
{
	int	ret;

	ret = 0;
	if (num < 0 && !(flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	if (flg.dot_mod && flg.prec_mod >= 0)
		ret += ft_pcr('0', flg.prec_mod - ft_ncbase(num * neg, 10)
				- !(num == 0));
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(num * (neg), 0, 10);
	return (ret);
}

int	ft_dflag(t_flags flg, va_list args)
{
	int				ret;
	long			num;
	int				neg;

	ret = 0;
	neg = 1;
	num = va_arg(args, int);
	if (num < 0)
		neg = -1;
	if (flg.prec_mod < 0)
	{
		flg.prec_mod = 1;
		flg.dot_mod = 0;
	}
	if (num < 0 && (flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	if (flg.zero_mod && !flg.dot_mod)
		ret += ft_pcr('0', ft_dspaces(flg, num * neg, 0) - (num < 0));
	else
		ret += ft_pcr(' ', ft_dspaces(flg, num * neg, 0) - (num < 0));
	ret += ft_paddedprinting(flg, num, neg);
	ret += ft_pcr(' ', ft_dspaces(flg, num * neg, 1) - (num < 0));
	return (ret + ft_ncbase(num * neg, 10)
		+ (num != 0 || flg.dot_mod == 0) + (num < 0));
}
