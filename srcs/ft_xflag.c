/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:34:52 by gaguado-          #+#    #+#             */
/*   Updated: 2021/03/09 17:01:12 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_spaces(t_flags flg, unsigned long num, int neg)
{
	int spaces;

	spaces = (int)(num != 0 || flg.dot_mod == 0);
	if (neg)
	{
		if (ft_abs(flg.prec_mod) <= ft_ncbase(num, 16) && flg.dot_mod)
			spaces = (flg.flagqtt_mod * -1) - ft_abs(flg.prec_mod) - spaces;
		else
			spaces = (flg.flagqtt_mod * -1) - ft_abs(ft_abs(flg.prec_mod)
				- ft_ncbase(num, 16)) - spaces;
	}
	else
	{
		if (ft_abs(flg.prec_mod) <= ft_ncbase(num, 16) && flg.dot_mod)
			spaces = flg.flagqtt_mod - ft_abs(flg.prec_mod) - spaces;
		else
			spaces = flg.flagqtt_mod - ft_abs(ft_abs(flg.prec_mod)
				- ft_ncbase(num, 16)) - spaces;
	}
	return (spaces);
}

int	ft_xflag(t_flags flg, va_list args, int mayus)
{
	int				ret;
	unsigned long	num;
	int				zeros;
	int				spaces;

	ret = 0;
	if (flg.asterisk_mod)
		flg.prec_mod = va_arg(args, int);
	num = (unsigned long)va_arg(args, void*);
	zeros = ft_abs(flg.prec_mod) - ft_ncbase(num, 16)
		- (num != 0 || flg.dot_mod == 0);
	spaces = ft_spaces(flg, num, 0);
	ft_print_char_repeatedly((flg.zero_mod && !flg.dot_mod) ? '0' : ' ',
		spaces);
	if (flg.dot_mod)
		ft_print_char_repeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ret += ft_putnubrbase(num, mayus, 16);
	spaces = ft_spaces(flg, num, 1);
	ft_print_char_repeatedly(' ', spaces);
	ret += (-1 * flg.flagqtt_mod) - ft_ncbase(num, 16);
	return (ret);
}
