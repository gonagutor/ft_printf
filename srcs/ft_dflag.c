/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:02:01 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 18:49:23 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_dspaces(t_flags flg, long num, int neg)
{
	int	spaces;
	int	nc;

	nc = ft_ncsigned(num) + 1;
	spaces = (int)(num != 0 || flg.dot_mod == 0);
	if (neg)
	{
		if (ft_abs(flg.prec_mod) <= nc + (num < 0) && flg.dot_mod)
			spaces = (flg.flagqtt_mod * -1) - ft_abs(flg.prec_mod) - spaces
				- (num < 0 && ft_abs(flg.prec_mod) <= nc)
				+ (nc == flg.prec_mod);
		else
			spaces = (flg.flagqtt_mod * -1) - ft_abs(ft_abs(flg.prec_mod)
					- ft_ncsigned(num)) - spaces;
	}
	else
	{
		if (ft_abs(flg.prec_mod) <= nc + (num < 0) && flg.dot_mod)
			spaces = flg.flagqtt_mod - ft_abs(flg.prec_mod) - spaces - (num < 0
					&& ft_abs(flg.prec_mod) <= nc) + (nc == flg.prec_mod);
		else
			spaces = flg.flagqtt_mod - ft_abs(ft_abs(flg.prec_mod)
					- ft_ncsigned(num)) - spaces;
	}
	return (spaces);
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
	if (num < 0 && (flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	ret++;
	if (flg.zero_mod && !flg.dot_mod)
		ret += ft_print_char_repeatedly('0', spaces);
	else
		ret += ft_print_char_repeatedly(' ', spaces);
	if (num < 0 && !(flg.zero_mod && !flg.dot_mod))
		ft_putchar_fd('-', 1);
	if (flg.dot_mod)
		ret += ft_print_char_repeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(ft_abs(num), 0, 10);
	spaces = ft_dspaces(flg, num, 1);
	ret += ft_print_char_repeatedly(' ', spaces);
	return (ret);
}

int	ft_dflag(t_flags flg, va_list args)
{
	int				ret;
	long			num;

	ret = 0;
	num = va_arg(args, int);
	if (flg.prec_mod < 0 && num != 0)
		flg.prec_mod = 0;
	ret += ft_dpadding(flg, num);
	if (num != 0 || flg.dot_mod == 0)
		return (ret + ft_ncsigned(num));
	else
		return (ret - 1);
}
