/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:01 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/17 19:50:22 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_dspaces(t_flags flg, long num, int neg)
{
	int spaces;

	spaces = (int)(num != 0 || flg.dot_mod == 0);
	if (neg)
	{
		if (ft_abs(flg.prec_mod) <= ft_ncsigned(num) + 1 + (num < 0)
			&& flg.dot_mod)
			spaces = (flg.flagqtt_mod * -1) - ft_abs(flg.prec_mod) - spaces
			- (num < 0 && ft_abs(flg.prec_mod) <= ft_ncsigned(num) + 1);
		else
			spaces = (flg.flagqtt_mod * -1) - ft_abs(ft_abs(flg.prec_mod)
				- ft_ncsigned(num)) - spaces;
	}
	else
	{
		if (ft_abs(flg.prec_mod) <= ft_ncsigned(num) + 1 + (num < 0)
			&& flg.dot_mod)
			spaces = flg.flagqtt_mod - ft_abs(flg.prec_mod) - spaces
			- (num < 0 && ft_abs(flg.prec_mod) <= ft_ncsigned(num) + 1);
		else
			spaces = flg.flagqtt_mod - ft_abs(ft_abs(flg.prec_mod)
				- ft_ncsigned(num)) - spaces;
	}
	return (spaces);
}

int	ft_dflag(t_flags flg, va_list args)
{
	int				ret;
	long			num;
	int				zeros;
	int				spaces;

	ret = 0;
	if ((flg.asterisk_mod && (!(flg.dot_mod || flg.prec_mod)
		|| flg.asterisk_mod >= 2)))
		flg.flagqtt_mod = va_arg(args, int);
	if ((flg.asterisk_mod && flg.prec_mod == 0 && flg.dot_mod) ||
		flg.asterisk_mod >= 2)
		flg.prec_mod = va_arg(args, int);
	num = va_arg(args, int);
	if (flg.prec_mod < 0 && num != 0)
		flg.prec_mod = 0;
	zeros = ft_abs(flg.prec_mod) - ft_ncsigned(num)
		- (num != 0 || flg.dot_mod == 0) + (num < 0);
	spaces = ft_dspaces(flg, num, 0);
	if (flg.minus_mod && flg.flagqtt_mod > 0)
		flg.flagqtt_mod *= -1;
	if (num < 0 && (flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	ft_print_char_repeatedly((flg.zero_mod && !flg.dot_mod) ? '0' : ' ',
		spaces);
	if (num < 0 && !(flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	if (flg.dot_mod)
		ft_print_char_repeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(ft_abs(num), 0, 10);
	spaces = ft_dspaces(flg, num, 1);
	ret += ft_print_char_repeatedly(' ', spaces);
	return (ret);
}
