/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:34:52 by gaguado-          #+#    #+#             */
/*   Updated: 2021/05/05 18:33:30 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_xspaces(t_flags flg, unsigned long num, int neg, int base)
{
	int	spaces;

	spaces = (int)(num != 0 || flg.dot_mod == 0);
	if (neg)
	{
		if (ft_abs(flg.prec_mod) <= ft_ncbase(num, base) && flg.dot_mod)
			spaces = (flg.flagqtt_mod * -1) - ft_abs(flg.prec_mod) - spaces;
		else
			spaces = (flg.flagqtt_mod * -1) - ft_abs(ft_abs(flg.prec_mod)
					- ft_ncbase(num, base)) - spaces;
	}
	else
	{
		if (ft_abs(flg.prec_mod) <= ft_ncbase(num, base) && flg.dot_mod)
			spaces = flg.flagqtt_mod - ft_abs(flg.prec_mod) - spaces;
		else
			spaces = flg.flagqtt_mod - ft_abs(ft_abs(flg.prec_mod)
					- ft_ncbase(num, base)) - spaces;
	}
	return (spaces);
}

int	ft_xflag(t_flags flg, va_list args, int mayus, int base)
{
	int				ret;
	unsigned long	num;
	int				zeros;
	int				spaces;

	ret = 0;
	num = va_arg(args, unsigned long);
	zeros = ft_abs(flg.prec_mod) - ft_ncbase(num, base)
		- (num != 0 || flg.dot_mod == 0);
	spaces = ft_xspaces(flg, num, 0, base);
	if (flg.zero_mod && !flg.dot_mod)
		ret += ft_print_char_repeatedly('0', spaces);
	else
		ret += ft_print_char_repeatedly(' ', spaces);
	if (flg.dot_mod)
		ret += ft_print_char_repeatedly('0', zeros);
	if (num != 0 || flg.dot_mod == 0)
		ft_putnubrbase(num, mayus, base);
	spaces = ft_xspaces(flg, num, 1, base);
	ret += ft_print_char_repeatedly(' ', spaces);
	return (ret + ft_ncbase(num, base) + (num != 0 || flg.dot_mod == 0));
}
