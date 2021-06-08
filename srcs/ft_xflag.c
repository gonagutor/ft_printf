/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:34:52 by gaguado-          #+#    #+#             */
/*   Updated: 2021/06/08 18:41:54 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_xspaces(t_flags flg, unsigned long num, int neg, int base)
{
	int	spaces;
	int	lzeros;
	int	numlen;

	spaces = 0;
	numlen = ft_ncbase(num, base) + 1;
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

int	ft_xflag(t_flags flg, va_list args, int mayus, int base)
{
	int				ret;
	unsigned int	num;
	int				zeros;
	int				spaces;

	ret = 0;
	num = va_arg(args, unsigned long);
	zeros = ft_abs(flg.prec_mod) - ft_ncbase(num, base)
		- 1;
	spaces = ft_xspaces(flg, num, 0, base);
	if (flg.zero_mod && (!flg.dot_mod || flg.prec_mod < 0))
		ret += ft_pcrepeatedly('0', spaces);
	else
		ret += ft_pcrepeatedly(' ', spaces);
	if (flg.dot_mod)
		ret += ft_pcrepeatedly('0', zeros + (num == 0));
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(num, mayus, base);
	spaces = ft_xspaces(flg, num, 1, base);
	ret += ft_pcrepeatedly(' ', spaces);
	return (ret + ft_ncbase(num, base) + (num != 0 || flg.dot_mod == 0));
}
