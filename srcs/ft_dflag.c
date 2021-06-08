/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:01 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/31 19:30:42 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_dspaces(t_flags flg, long num, int neg)
{
	int	spaces;
	int	lzeros;
	int	numlen;

	spaces = 0;
	numlen = ft_ncsigned(num) + 1;
	lzeros = 0;
	if (flg.dot_mod && flg.prec_mod > 0)
		lzeros = ft_abs(flg.prec_mod) - ft_ncsigned(num)
			- (num != 0 || flg.dot_mod == 0) + (num < 0);
	if (lzeros < 0 || flg.prec_mod < 0)
		lzeros = (num == 0);
	if (!neg)
		spaces = flg.flagqtt_mod - numlen - lzeros
			+ (num == 0 && flg.dot_mod != 0);
	else
		spaces = (flg.flagqtt_mod * -1) - numlen - lzeros
			+ (num == 0 && flg.dot_mod != 0);
	return (spaces + (flg.minus_mod && flg.zero_mod));
	// This does not work with negatives because it does not take into account the minus at the front
}

int	ft_dpadding(t_flags flg, int num)
{
	int	zeros;
	int	spaces;
	int	ret;

	ret = 0;
	zeros = ft_abs(flg.prec_mod) - ft_ncsigned(num)
		- (num != 0 || flg.dot_mod == 0) + (num < 0);
	spaces = ft_dspaces(flg, num, 0);
	if (flg.minus_mod && flg.flagqtt_mod > 0)
		flg.flagqtt_mod *= -1;
	if (num < 0 && (flg.zero_mod && (!flg.dot_mod || flg.prec_mod < 0)))
		ft_putchar_fd('-', 1);
	ret++;
	if (flg.zero_mod && (!flg.dot_mod || flg.prec_mod < 0))
		ret += ft_pcrepeatedly('0', spaces);
	else
		ret += ft_pcrepeatedly(' ', spaces);
	if (num < 0 && !(flg.zero_mod && (!flg.dot_mod || flg.prec_mod < 0)))
		ft_putchar_fd('-', 1);
	if (flg.dot_mod)
		ret += ft_pcrepeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(ft_abs(num), 0, 10);
	spaces = ft_dspaces(flg, num, 1);
	return (ret += ft_pcrepeatedly(' ', spaces));
}

int	ft_dflag(t_flags flg, va_list args)
{
	int				ret;
	long			num;

	ret = 0;
	num = va_arg(args, int);
	ret += ft_dpadding(flg, num);
	if (num != 0 || flg.dot_mod == 0)
		return (ret + ft_ncsigned(num));
	else
		return (ret - 1);
}
